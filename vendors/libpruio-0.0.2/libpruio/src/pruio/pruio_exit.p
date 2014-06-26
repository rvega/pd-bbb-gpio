// \file pruio_exit.p
// \brief Source code for exit instructions, restore devices configurations.
// Licence: LGPLv2 (http://www.gnu.org/licenses/lgpl-2.0.html)
// Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net

//  compile for .bi output
//    pasm -V3 -y -CPru_Exit pruio_exit.p

#include "pruio.hp"
#define IRPT PRUIO_IRPT + 16

#define CTBIR        0x22020
#define CONST_PRUCFG C4

// base adresses
#define CM_WKUP_ADC_TSC_CLKCTRL 0x44E004BC
#define ADC_BASE 0x44E0D000

// register aliases
#define AdcP r1   // ADC base address

.origin 0

  // Enable OCP master port (clear SYSCFG[STANDBY_INIT])
  LBCO r0, CONST_PRUCFG, 4, 4
  CLR  r0, r0, 4
  SBCO r0, CONST_PRUCFG, 4, 4

  MOV  r1, 0x44E10800        // PinMux registers
  LDI  r0, 0                 // DRam pointer
  LBBO r2, r0, 4, 4          // load start of data
  QBEQ AdcOff, r2, 0         // no data, just switch off ADC

CopyBalls:
  LBBO r3, r2, 0, 1          // load pin configuration
  SBBO r3, r1, 0, 1          // save pin configuration
  ADD  r1, r1, 4             // increase PinMux pointer
  ADD  r2, r2, 1             // increase DRam pointer
  QBGE CopyBalls, r2.b0, PRUIO_BALL_AZ // check for last index


  ADD  r2, r2, 3           // count next word border
  AND  r2.b0, r2.b0, 0xFC  // clear last bits (to word border)

  LDI  r1, PRUIO_GPIO_OFFS   // first GPIO data
CopyGpio:
  LBBO r3, r1, 0, 4          // load GPIO base address
  CLR  r4, r3, 8             // load GPIO REVISION register address

  LBBO r5, r2, 0, PRUIO_GPIO_DATA // load config
  QBNE NextGpio, r9, 2       // skip when initialy down
  SBBO r6, r3, 0x34, 4       // set GPIO OE register
  SBBO r7, r4, 0x2C, 8       // set GPIO INT0 & INT1 registers
NextGpio:
  SBBO r9, r5, 0, 4          // set GPIO clock
  ADD  r2, r2, PRUIO_GPIO_DATA // next conf data
  ADD  r1, r1, PRUIO_GPIO_BLCK // next GPIO block
  QBGE CopyGpio, r1, 0xA0      // last GPIO block reached?


  MOV  AdcP, ADC_BASE      // ADC registers address base
  LBBO r3, r2, 0   , 4     // load REVISION
  QBEQ AdcOff, r3, 0       // branch in case of no data

AdcIdle:
  LBBO r3,  AdcP, 0x44, 4  // get ADC status
  QBBS AdcIdle, r3, 5      // ADC busy, wait

  LDI  r3, 0b100           // disable ADC, step config writable
  SBBO r3,  AdcP, 0x40,  4 // set CTRL register

  LBBO r3, r2, 0xA4, 64    // load step config registers 9 - 16
  SBBO r3, AdcP, 0xA4, 64  // restore in ADC
  LBBO r3, r2, 0x64, 64    // load step config registers 1 - 8
  SBBO r3, AdcP, 0x64, 64  // restore in ADC
  LBBO r3, r2, 0x24, 64    // load config registers
  SBBO r3, AdcP, 0x24, 64  // restore in ADC
  LBBO r3, r2, 0x10,  4    // load SYSCONFIG register
  SBBO r3, AdcP, 0x10,  4  // restore in ADC
  JMP  AdcDone

AdcOff:
  MOV  r4, CM_WKUP_ADC_TSC_CLKCTRL // load registers address
  LDI  r3, 0b00
  SBBO r3.b0, r4, 0, 1             // set CM_WKUP_ADC_TSC_CLKCTRL register


AdcDone:
  MOV  r1, PRUIO_MSG_EXIT_OK
  SBBO r1, r0, 0, 4        // store status information
  MOV  r31.b0, IRPT        // send notification to host
  HALT
