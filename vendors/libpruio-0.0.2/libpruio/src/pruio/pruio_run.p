// \file pruio_run.p
// \brief Source code for driver instructions, operate devices.
// Licence: LGPLv2 (http://www.gnu.org/licenses/lgpl-2.0.html)
// Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net

//  compile for .bi output
//    pasm -V3 -y -CPru_Run pruio_run.p

#include "pruio.hp"
#define IRPT PRUIO_IRPT + 16

#define CONST_PRUCFG C4
#define CTBIR      0x22020

// base adresses
#define CM_WKUP_ADC_TSC_CLKCTRL 0x44E004BC
#define ADC_BASE 0x44E0D000
#define DRamP C24 // PRU0 DRam

// register aliases
#define  AdcP r1  // ADC base adress
#define FiFoP r2  // FiFo0 adress
#define  SmpC r3  // number of samples
#define  TimV r4  // timer value
#define  StpV r5  // step mask (active steps)
#define  MdsV r6  // modus value (12 to 16 bits) + ClkDiv
#define  POfs r9  // offset for ADC parameters
#define UR r10  // universal registers
#define U2 r11  // universal register 2
#define U3 r12  // universal register 3
#define U4 r13  // universal register 4
#define U5 r14  // universal register 5
#define U6 r15  // universal register 6
#define U7 r16  // universal register 7
#define U8 r17  // universal register 8

.origin 0

  // Enable OCP master port (clear SYSCFG[STANDBY_INIT])
  LBCO  r0, CONST_PRUCFG, 4, 4
  CLR   r0.t4
  SBCO  r0, CONST_PRUCFG, 4, 4

  ZERO &r0, 4           // clear register R0
  MOV  UR, CTBIR        // load address
  SBBO r0, UR, 0, 4     // make C24 point to 0x0 (PRU-0 DRAM) and C25 point to 0x2000 (PRU-1 DRAM).

  MOV  AdcP, ADC_BASE   // ADC registers base address
  LBBO UR, AdcP, 0, 4   // load REVISION from ADC
  QBNE AdcUp, UR, 0     // branch when up, otherwise stop with error

  MOV  UR, PRUIO_MSG_ADC_ERRR
  SBCO UR, DRamP, 0, 4  // store status information
  MOV  r31.b0, IRPT     // Send notification to host for program stopping
  HALT

AdcUp:
  LDI  POfs, PRUIO_ADC_OFFS // load parameter offset
  LBBO SmpC, POfs, 0, 16    // load parameters from DRam
  SET  FiFoP, AdcP, 8       // ADC FiFo-0 address (0x9 for FiFo-1)

  SBBO r0, AdcP, 0x10, 1   // reset SYSCONFIG register to zero

AdcIdle:
  LBBO UR, AdcP, 0x44, 4   // get ADC status
  QBBS AdcIdle, UR, 5      // ADC busy, wait

  LBBO UR, POfs, 16, 32    // load configuration register values
  SET  U8.t2               // step config writable
  CLR  U8.t0               // disable TSC_ADC_SS (during configuration)
  SBBO UR, AdcP, 0x24, 32  // set ADC registers (0x24 to 0x40)

  LBBO UR, POfs, 184, 8    // load idle step config from shared memory
  QBEQ AdcConf, U2, 0      // skip idle config adjustment

  LSL  U2, U2, 3           // multiply step# by 8 (len(step{config,delay}))
  ADD  U2, U2, 48          // add offset
  LBBO UR, POfs, U2, 4     // load config from first active step
  AND  UR.b0, UR.b0, 0b11100000 // mask valid bits

AdcConf:
  SBBO UR, AdcP, 0x58, 4   // set idle step config
  LBBO UR, POfs, 48, 8     // load charge step
  SBBO UR, AdcP, 0x5C, 8   // set charge step
  LBBO UR, POfs, 56, 64    // load step 1-8 config
  SBBO UR, AdcP, 0x64, 64  // set config
  LBBO UR, POfs, 120, 64   // load step 9-16 config
  SBBO UR, AdcP, 0xA4, 64  // set config

  SBBO MdsV.w2, AdcP, 0x4C, 2 // set ADC_CLKDIV register
  MIN  MdsV, MdsV.b0, 4       // limit sample bit shifts to 4

  LBBO UR, AdcP,   0x40, 2 // load ADC control register
  CLR  UR.t2               // step config non-writable
  SET  UR.t1               // enable step IDs in FiFo
  SET  UR.t0               // enable TSC_ADC_SS (after configuration)
  SBBO UR, AdcP, 0x40, 2   // store ADC control register

  ZERO &UR, 34
  SBCO UR, DRamP, PRUIO_ADC_BUFF - 2, 34 // initialize shared memory (1+16 zero values)

AdcClear:
  LBBO UR, AdcP, 0xE4, 4   // get FiFo-0 counter
  QBEQ AdcDone, UR, 0      // no value, start
  LBBO U2, FiFoP, 0, 4     // get old pending ADC value
  JMP  AdcClear            // again, until last value

AdcDone:
  QBLT MmInit, SmpC, 1     // MM mode required

  SBBO StpV, AdcP, 0x54, 3 // enable steps, lets go for single samples
  MOV  UR, PRUIO_MSG_IO_OK
  SBCO UR, DRamP, 0, 4     // store status information
  MOV  r31.b0, IRPT        // send notification to host
  LDI  U8, PRUIO_GPIO_OFFS // offset first GPIO address

GpioConf:
  LBBO UR, U8, 0, 16       // get GPIO base address, CLR / SET masks & OutE
  SBBO U4, UR, 0x34, 4     // set OE register
  SBBO U2, UR, 0x90, 8     // set GPIO states (CLR / SET)
  ZERO &U2, 8
  SBBO U2, U8, 4, 8        // reset CLR / SET masks

  ADD  U8, U8, PRUIO_GPIO_BLCK // next GPIO
  QBGE GpioConf, U8, 0xA0      // last GPIO reached?

  MOV  UR, 0x44E10800       // pin mux registers
  LDI  U6, PRUIO_BALL_OFFS // offset BallConf array

PinsLoop:
  LBBO U3, U6, PRUIO_BALL_AZ + 1, 1 // get pin ref
  QBEQ PinsSkip, U3, 255   // skip if locked

  LBBO U4, U6, 0, 1        // get config
  SBBO U4, UR, 0, 1        // set config

PinsSkip:
  ADD  UR, UR, 4           // next pinmux
  ADD  U6, U6, 1           // next pin
  QBGE PinsLoop, U6.b0, PRUIO_BALL_AZ // last pin reached?

  LDI  U6, PRUIO_BALL_OFFS // offset BallConf array
  MOV  U7, PRUIO_MSG_INIT_OK // ready message
  SBCO U7, DRamP, 4, 4     // set state info
  MOV  UR, 0x44E10800      // pin mux registers
  LDI  U8, PRUIO_GPIO_OFFS // reset to first GPIO address


IoLoop:
  LBBO U2, AdcP, 0x44, 4   // get ADC status
  QBBS IoConf, U2, 5       // ADC busy, skip restart
  SBBO StpV, AdcP, 0x54, 3 // restart ADC

IoConf:
  LBCO U4, DRamP, 4, 4     // get re-config order
  QBEQ IoGpio, U4, U7      // no re-config, skip
  QBBS IoBall, U4.t31      // ball re-config, jump

  MOV  StpV, U4            // set new steps mask
  SBCO U7, DRamP, 4, 4     // reset state info
  JMP  IoGpio

IoBall:
  LBBO U3, U6, U4.b0, 1    // get new config
  LSL  U4, U4, 2           // calc pinmux offset
  SBBO U3, UR, U4, 1       // set new config
  SBCO U7, DRamP, 4, 4     // reset state info
  LBBO U2, U8, 0, 16       // get GPIO base address and CLR / SET masks and OE
  SBBO U5, U2, 0x34, 4     // re-config GPIO OE register
  JMP  IoGpioDo

IoGpio:
  LBBO U2, U8, 0, 12       // get GPIO base address and CLR / SET masks
IoGpioDo:
  SBBO U3, U2, 0x90, 8     // set GPIO states (CLR / SET)
  ZERO &U3, 8              // clear registers
  SBBO U3, U8, 4, 8        // reset GPIO CLR / SET masks

  LBBO U3, U2, 0x38, 8     // get GPIO states (input / output)
  OR   U3, U3, U4          // mix both together
  SBBO U3, U8, 16, 8       // store GPIO state
  ADD  U8, U8, PRUIO_GPIO_BLCK // next GPIO
  QBGE IoAdc, U8, 0xA0     // last GPIO reached?
  LDI  U8, PRUIO_GPIO_OFFS // reset to first GPIO address

IoAdc:
  LBBO U2, AdcP, 0xE4, 4   // get FiFo-0 counter
  QBEQ IoLoop, U2, 0       // no value, check restart

  LBBO U2, FiFoP, 0, 4     // get ADC value
  LSL  U3, U2.b2, 1        // extract step ID, calc position
  ADD  U4, U2.b2, 1        // calc step number
  QBBS IoSave, StpV, U4    // skip active steps
  LDI  U2.w0, 0            // zero inactive steps
IoSave:
  LSL  U2, U2, MdsV.b0     // shift to 13, 14, 15 or 16 bit
  SBBO U2.w0, U3, PRUIO_ADC_BUFF, 2 // store ADC value to shared memory
  JMP  IoLoop


#define TrgC r7   // trigger count register
#define TrgR r8   // trigger register

#define LUpR r9   // buffer size
#define TarR r10  // pointer to result buffer

#define SmpR r11  // sample register
#define FifR r12  // FiFo counter register
#define PtrR r13  // pointer register
#define UniR r14  // universal register

#define CntR r15  // counter register
#define CmpR r16  // compare register

#define TrgU r17  // temporary store upper limit
#define TChC 0xFF // start value for trigger step#

MmInit:
  LBCO r13, C26, 0x40, 4  // read 3 IEP timer control register
  OR   r13, r13, 0b11     // set count reset and enable compare 0 event
  LDI  r14, 0             // reset status
  MOV  r15, TimV          // set loop period
  SBCO r13, C26, 0x40, 12 // save config

  LDI  UniR, 0x0551       // enable timer counter, 5 increments
  SBCO UniR, C26, 0, 4    // save IEP GLOBAL_CFG register

MmWait:
  MOV  CmpR, PRUIO_MSG_MM_WAIT
  SBCO CmpR, DRamP, 0, 4  // store status information
  MOV  r31.b0, IRPT       // send notification to host
  LDI  CmpR, 0            // reset compare register
  LDI  TrgC, PRUIO_TRG_PARA + 12 // reset trigger counter
  WBS  r31.t31            // wait for restart
  WBC  r31.t31            // go

TrgPrep:
  LBBO SmpR, AdcP, 0x44, 4 // get ADC status
  QBBS TrgPrep, SmpR, 5    // ADC busy, wait
TrgClr:
  LBBO CntR, AdcP, 0xE4, 4 // get FiFo-0 counter
  QBEQ TrgSet, CntR, 0     // FiFo-0 empty, start
  LBBO SmpR, FiFoP, 0, 4   // drop old pending ADC value
  JMP  TrgClr              // again, until FiFo-0 is empty


TrgSet:
  LBCO TrgR, DRamP, TrgC.b0, 4  // load trigger setup
  QBEQ MmStart, TrgR, 0         // no trigger, start measurement

  SUB  TrgC.b1, TrgC.b0, PRUIO_TRG_PARA + 12
  LSR  TrgC.b1, TrgC.b1, 2      // calc trigger number
  MOV  SmpR, PRUIO_MSG_MM_TRG1  // load trigger message
  SUB  SmpR, SmpR, TrgC.b1      // adapt message
  SBCO SmpR, DRamP, 0, 4        // store status information

  LSR  TrgC.w2, TrgR.w2, 6      // post-trigger value counter
  QBBS TrgGpio, TrgR.t21        // GPIO trigger bit, jump

  QBBS TrgAllS, TrgR.t20        // all steps bit, start
  AND  TrgC.b1, TrgR.b0, 0b1111 // get step#, only values 0 to 15 are valid
  JMP  TrgSamp

TrgAllS:
  LDI  TrgC.b1, TChC   // clear step number

TrgSamp:
  AND  TrgR.b2, TrgR.b2, 0xF    // validate sample compare bits in .w1
  QBBS TrgFast, TrgR.t4         // fast trigger bit, start

#define T  r10   // target (pointer), don't change order
#define Si r11   // size (in bytes), don't change order
#define S  r12   // source (pointer), don't change order
#define I  r0.w2 // bytes index
#define Az r0.b0 // real chunk size (must be r0)
#define D  r14   // data, don't change order
#define ChMx 64  // chunk size limit (depends on free data registers)

// pre-trigger setup, initialize memory (zero)
  MOV  Az, ChMx         // start with max chunck size
  ZERO &D, ChMx         // clear data registers
  LBCO T, DRamP, PRUIO_TRG_PARA + 4, 8 // load target and counter
  SUB  I, Si, ChMx - 32 // initialize index (32 = 2 byte * 16 max steps)

Check0:
  QBGE Store0, I, Si    // complete chunk in range?
  ADD  Az, I, ChMx      // chunk size = rest
  LDI  I, 0             // index = zero

Store0:
  SBBO D, T, I, b0      // save chunk to memory
  QBEQ TrgPre, I, 0     // ground reached? otherwise continue
  SUB  I, I, Az         // set index for next chunk
  JMP  Check0           // go again

TrgPre:
  MOV  LUpR, Si         // initialize upper limit (ring buffer)
  LSR  TrgC.w2, Si, 1   // pre-trigger samples counter
  LDI  TrgR.b3, TChC    // initialize b3 (step offset)

  JMP  MmStart2


TrgGpio:
  AND  TrgC.b1, TrgR.w1, 0b11111   // GPIO bit index
  AND  UniR, TrgR.w1,  0b1100000   // index of base address (PRUIO_GPIO_BLCK must be 32)
  ADD  UniR, UniR, PRUIO_GPIO_OFFS // add DRam offset
  LBBO PtrR, UniR, 0, 4            // get GPIO base address

  QBBS TrgGpioLow, TrgR.t7         // check negative bit

TrgGpioHigh:
  LBBO SmpR, PtrR, 0x38, 8         // load GPIO states (input / output)
  OR   SmpR, SmpR, FifR            // mix both together
  QBBC TrgGpioHigh, SmpR, TrgC.b1  // again until GPIO pin gets high
  JMP  TrgEvent

TrgGpioLow:
  LBBO SmpR, PtrR, 0x38, 8         // load GPIO states (input / output)
  OR   SmpR, SmpR, FifR            // mix both together
  QBBS TrgGpioLow, SmpR, TrgC.b1   // again until GPIO pin gets low
  JMP  TrgEvent


TrgFast:
  MOV  UniR, CmpR
  LDI  CmpR, 2                    // prepare step mask
  LSL  CmpR, CmpR, TrgC.b1        // left shift mask
  QBEQ TrgSkip, CmpR, UniR        // same step, skip sampling


TrgStart:
  SBBO CmpR, AdcP, 0x54, 3        // enable ADC step, go for trigger sample
TrgWait:
  LBBO SmpR, AdcP, 0xE4, 4        // get FiFo-0 counter
  QBEQ TrgWait, SmpR, 0           // no value, wait
  LBBO SmpR, FiFoP, 0, 4          // get ADC value (32 bit)

TrgSkip:
  QBBC TrgTest, TrgR.t6           // check delta trigger
  CLR  TrgR.t6                    // clear delta bit
  QBBS TrgDeltaLt, TrgR.t7        // check negative bit
  ADD  TrgR.w1, TrgR.w1, SmpR.w0  // new pos. trigger value, based on current sample
  LDI  UniR, 0xFF0                // maximum
  MIN  TrgR.w1, TrgR.w1, UniR     // limit to 0xFF0
  JMP  TrgTest                    // test the sample
TrgDeltaLt:
  QBLT TrgFixLt, TrgR.w1, SmpR.w0 // overflow, fix it
  SUB  TrgR.w1, SmpR.w0, TrgR.w1  // new neg. trigger value, based on current sample
  QBLE TrgTest, TrgR.w1, 0x10     // big enough, continue
TrgFixLt:
  LDI  TrgR.w1, 0xF               // load minimal trigger value

TrgTest:
  QBBS TrgGt, TrgR.t7             // check negative bit
  QBGT TrgStart, SmpR.w0, TrgR.w1 // check greater
  JMP  TrgEvent
TrgGt:
  QBLT TrgStart, SmpR.w0, TrgR.w1 // check less


TrgEvent:
  QBBC TrgNext, TrgR.t5     // check post-trigger bit
  SBCO CntR, C26,  0x0C, 4  // do a post trigger, reset timer
TrgPost:
  QBEQ TrgNext, TrgC.w2, 0  // jump out when post-trigger done
  SBCO CntR, C26,  0x44, 4  // clear timer CMP_STATUS bits
TrgTimer:
  LBCO UniR, C26,  0x44, 4  // load CMP_STATUS register
  QBBC TrgTimer, UniR, 0    // wait for time-out
  SUB  TrgC.w2, TrgC.w2, 1  // decrease counter
  JMP  TrgPost              // next loop


TrgNext:
  ADD  TrgC.b0, TrgC.b0, 4  // increase pointer to next trigger setting
  QBGE TrgSet, TrgC.b0, 28  // next trigger, up to 4 (offset 4+6*4) !!!


MmStart:
  LBCO LUpR, DRamP, PRUIO_TRG_PARA, 8 // load storage setup (LUpR = max, TarR = pointer)
MmStart2:
  SBBO StpV, AdcP, 0x54, 3   // enable ADC steps, go for samples
  SBCO CntR, C26,  0x0C, 4   // reset timer
  SBCO CntR, C26,  0x44, 4   // clear timer CMP_STATUS bits
  LDI  PtrR, 0               // initialize index
  LDI  CntR, 1               // initialize counter

MmLoop:
  QBGT MmAdc,  CntR, SmpC // SmpC > CntR -> continue
  QBEQ MmWait, TrgR, 0    // no ring buffer, finish
  QBEQ MmWait, TrgR, TrgU // good luck, nothing to sort

// re-sort ring buffer
  SUB  TrgC, TrgU, TrgR  // calculate byte size to copy
  MOV  LUpR, TarR        // tmp save TarR (r17 in data range)
// copy upper part to DRam
  ADD  S, TarR, TrgR     // load source pointer
  MOV  Si, TrgC          // load byte size to copy
  LDI  T, PRUIO_ADC_OFFS // load target pointer (DRam)
  CALL Copy
// copy lower part to upper end
  MOV  S, LUpR           // load source pointer
  MOV  Si, TrgR          // load byte size to copy
  ADD  T, S, TrgC        // load target pointer
  CALL Copy
// copy DRam to start
  MOV  S, PRUIO_ADC_OFFS // load source pointer
  MOV  Si, TrgC          // load byte size to copy
  MOV  T, LUpR           // load target pointer
  CALL Copy
  JMP  MmWait            // finish


MmAdc:
  LBBO CmpR, AdcP, 0x44, 4   // get ADC status
  QBBS MmAdc, CmpR, 5        // ADC busy, wait

MmTimer:
  LBCO CmpR, C26,  0x44, 4   // load CMP_STATUS register
  QBBC MmTimer, CmpR, 0      // wait for time-out

  SBBO StpV, AdcP, 0x54, 3   // enable ADC steps, go for next sample
  SBCO CmpR, C26,  0x44, 4   // clear counter timeout bits

MmFetch:
  LBBO FifR, AdcP, 0xE4, 4   // get FiFo-0 counter
  QBEQ MmLoop, FifR, 0       // no value, next loop
  LBBO SmpR, FiFoP, 0, 4     // get one 32-bit ADC value

  QBEQ MmLsl, TrgC.w2, 0       // trigger done
  QBEQ MmPos, TrgC.b1, TChC    // all trigger steps, check
  QBNE MmNoT, TrgC.b1, SmpR.b2 // not our trigger step, skip

MmPos:
  QBNE MmCheck, TrgR.b3, TChC  // trigger step position already known
  MOV  TrgR.b3, CntR           // store trigger step position
  ADD  LUpR, LUpR, PtrR        // more room for step samples before trigger step

MmCheck:
  QBBC MmTest, TrgR.t6            // check relative trigger bit
  CLR  TrgR.t6                    // clear relative bit

  QBBS MmLess, TrgR.t7            // check greater or less bit

  ADD  TrgR.w1, TrgR.w1, SmpR.w0  // new trigger value, based on current sample
  LDI  CmpR, 0xFF0
  MIN  TrgR.w1, TrgR.w1, CmpR     // limit 0xFF0
  JMP  MmTest                     // test sample

MmLess:
  QBLT MmFixL, TrgR.w1, SmpR.w0   // overflow, fix it
  SUB  TrgR.w1, SmpR.w0, TrgR.w1  // new trigger value, based on current sample
  QBLE MmTest, TrgR.w1, 0x10      // big enough, continue

MmFixL:
  LDI  TrgR.w1, 0xF               // load minimal trigger value

MmTest:
  QBBS MmGt, TrgR.t7           // check greater or less bit

  QBGT MmNoT, SmpR.w0, TrgR.w1 // check greater
  JMP  MmTrg

MmGt:
  QBLT MmNoT, SmpR.w0, TrgR.w1 // check less

MmTrg:
  LDI  TrgC, 0                // got the trigger, reset register
  MOV  TrgR, PtrR             // save ring buffer pointer in TrgR
  MOV  TrgU, LUpR             // save ring buffer size in TrgU
  MOV  PtrR, LUpR             // initialize pointer to real memory position
  LSR  CntR, LUpR, 1          // initialize counter to real position
  LBCO LUpR, DRamP, PRUIO_TRG_PARA, 4 // get end of external memory

  JMP  MmLsl

MmNoT:
  MIN  CntR, CntR, TrgR.b3    // hold down counter while waiting for trigger

MmLsl:
  LSL  SmpR, SmpR, MdsV.b0    // shift to 13, 14, 15 or 16 bit

  QBGT MmWrite, PtrR, LUpR    // upper limit > PtrR -> no overflow, skip reset
// ToDo: send event to ARM here ???
  LDI  PtrR, 0                // reset pointer

MmWrite:
  SBCO PtrR, DRamP, 0, 4    // store status information
  SBBO SmpR, TarR, PtrR, 2  // write lower 16 bit to memory
  ADD  CntR, CntR, 1        // increase samples counter
  ADD  PtrR, PtrR, 2        // increase pointer value
  JMP  MmFetch


Copy:
  MOV  Az, ChMx       // start with max chunck size
  SUB  I, Si, Az      // initialize index

CheckC:
  QBGE StoreC, I, Si  // complete chunk in range?
  ADD  Az, I, ChMx    // chunk size = rest
  LDI  I, 0           // index = zero

StoreC:
  LBBO D, S, I, b0    // load a chunk
  SBBO D, T, I, b0    // save it

  QBNE ContC, I, 0    // ground reached? otherwise continue
  RET

ContC:
  SUB  I, I, Az       // set index for next chunk
  JMP  CheckC         // go again
