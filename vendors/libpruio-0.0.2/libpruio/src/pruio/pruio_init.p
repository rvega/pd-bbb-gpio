// \file pruio_init.p
// \brief Source code for init instructions, read devices configurations.
// Licence: LGPLv2 (http://www.gnu.org/licenses/lgpl-2.0.html)
// Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net

//  compile for .bi output
//    pasm -V3 -y -CPru_Init pruio_init.p

#include "pruio.hp"
#define IRPT PRUIO_IRPT + 16

#define CTBIR      0x22020
#define CONST_PRUCFG C4

// base adresses
#define CM_WKUP_ADC_TSC_CLKCTRL 0x44E004BC
#define ADC_BASE 0x44E0D000

// register aliases
#define  AdcP r20

.origin 0

  // Enable OCP master port (clear SYSCFG[STANDBY_INIT])
  LBCO r0, CONST_PRUCFG, 4, 4
  CLR  r0, r0, 4
  SBCO r0, CONST_PRUCFG, 4, 4

  MOV  r1, 0x44E10800        // PinMux registers
  LDI  r2, PRUIO_BALL_OFFS   // DRam pointer

CopyBalls:
  LBBO r3, r1, 0, 1          // load pin configuration
  SBBO r3, r2, 0, 1          // save pin configuration
  ADD  r1, r1, 4             // increase PinMux pointer
  ADD  r2, r2, 1             // increase DRam pointer
  QBGE CopyBalls, r2.b0, PRUIO_BALL_AZ // check for last index


  LDI  r1, PRUIO_GPIO_OFFS // address of first GPIO data
  LDI  r10, 2              // clock value
  LDI  r0, 0               // to reset clock address and store status

  ADD  r2, r2, 3           // count next word border
  AND  r2.b0, r2.b0, 0xFC  // clear last bits (to word border)
  SBBO r2, r0, 4, 4        // store GPIO begin (for host)

CopyGpio:
  LBBO r3, r1, 0, 8        // load GPIO base & clock address
  SBBO r0, r1, 4, 4        // clear clock address
  ZERO &r5, 20             // clear transfer registers (r5-r9)
  LBBO r8, r4, 0, 4        // load GPIO CLK register
  QBEQ GpioUp, r8, 2       // allready up?

  SBBO r10, r4, 0, 4       // set GPIO CLK register
GpioWait:
  ADD  r9, r9, 1           // count timeout
  LBBO r6, r4, 0, 4        // load GPIO CLK register
  QBEQ GpioUp, r6, r10     // GPIO is up, read conf
  QBLT GpioWait, r9.b1, 16 // wait until timeout
  MOV  r5, 0xFFFFFFFF      // OE default (all inputs)
  SBBO r5, r3, 0x34, 4     // store GPIO OE register
  SBBO r5, r1, 12, 4       // store also in GPIO array
  JMP  GpioDone            // skip when timeout

GpioUp:
  LBBO r5, r3, 0x34, 4     // load GPIO OE register
  CLR  r7, r3, 8           // calc GPIO REVISION register address
  LBBO r6, r7, 0x2C, 8     // load GPIO INT0 & INT1 registers

GpioDone:
  SBBO r4, r2, 0, PRUIO_GPIO_DATA // save config
  ADD  r2, r2, PRUIO_GPIO_DATA    // next conf data
  ADD  r1, r1, PRUIO_GPIO_BLCK    // next GPIO block
  QBGE CopyGpio, r1.b0, 0xA0      // last GPIO block reached?


  MOV  AdcP, ADC_BASE   // ADC registers address base
  LBBO r3, AdcP, 0, 4   // load REVISION from ADC
  QBNE CopyAdc, r3, 0   // skip ADC wake-up

  // wake-up ADC
  MOV  r9, CM_WKUP_ADC_TSC_CLKCTRL // load register address
  LDI  r8, 0b10
  SBBO r8.b0, r9, 0, 1             // set register

  LDI  r5, 0            // load timeout counter
AdcNotUp:
  LBBO r4, AdcP,  0, 4  // load ADC REVISION
  QBNE AdcUp, r4, 0     // branch if ADC is up
  ADD  r5, r5, 1
  QBGT AdcNotUp, r5.b1, 16 // wait until timeout
AdcUp:
  SBBO r3, r2, 0, PRUIO_ADC_EMPTY // store REVISION (if any) and counter
  JMP  AdcDone


CopyAdc:
  LBBO r4, AdcP,   4, 60 // load further 15 registers
  SBBO r3, r2,   0, 64   // store in Dram
  LBBO r3, AdcP,  64, 64 // load 16 registers
  SBBO r3, r2,  64, 64   // store in Dram
  LBBO r3, AdcP, 128, 64 // load 16 registers
  SBBO r3, r2, 128, 64   // store in Dram
  LBBO r3, AdcP, 192, 36 // load 8 registers
  SBBO r3, r2, 192, 36   // store in Dram (synchronize with PRUIO_ADC_DATA)

AdcDone:
  MOV  r1, PRUIO_MSG_INIT_OK
  SBBO r1, r0, 0, 4      // store status information
  MOV  r31.b0, IRPT      // send notification to host
  HALT
