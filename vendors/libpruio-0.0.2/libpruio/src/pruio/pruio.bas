/'* \file pruio.bas
\brief The main source code of the library.

This is the main source code of the library. You may compile it by `fbc
-dylib pruio.bas` to get a small library file (small, because the C
wrapper functions are not included as in the original version).

'/


/'* \mainpage libpruio

Welcome to library libpruio,

- a driver for ARM33xx micro processors,
- developed on [Beaglebone hardware](http://www.beaglebone.org) for
- analog input and
- digital input and output.

It's designed to support easy configuration and data handling at high
speed. *libpruio* controls the subsystems

- Programmable Realtime Unit SubSystem (= PRUSS or just PRU),
- Touch Screen Controler and Analog-to-Digital Convertor SubSystem (= TSC_ADC_SS or just ADC),
- Control Module
- General Purpose Input / Outputs (= GPIO)

by software running at the real time unit (PRU). Once installed, this
library can configure and control the devices from single source (no
need for further overlays or the device tree compiler). The driver
supports two run modi

- digital and analog lines conrolled by the host (IO mode) and
- analog measurements with accurate timing controlled by the PRU (MM mode).

\em libpruio is developed and tested on a Beaglebone Black under Ubuntu
13.10 and should run on all Beaglebone platforms with Debian based
LINUX operating system. It's compiled by the
[FreeBasic compiler](http://www.freebasic.net). A wrapper for C
programming language is included.

Find more information in the Description pages

- \subpage ChaFeatures
- \subpage ChaMemory
- \subpage ChaPreparation
- \subpage ChaExamples
- \subpage ChaMessages
- \subpage ChaFE

or at the world wide web:

 - [en: libpruio (BB D/A - I/O fast and easy)](http://www.freebasic.net/forum/viewtopic.php?f=14&t=22501)
 - [de: libpruio (D/A - I/O schnell und einfach)](http://www.freebasic-portal.de/downloads/fb-on-arm/libpruio-325.html)


\section SecLicence Licence:

\subsection SubLicLib libpruio (LGPLv2):

Copyright &copy; 2014 by \Email

This program is free software; you can redistribute it and/or modify it
under the terms of the Lesser GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-
1301, USA. For further details please refer to:
http://www.gnu.org/licenses/lgpl-2.0.html

\subsection SubLicExa Examples (GPLv3):

Copyright &copy; 2014 by \Email

The examples of this bundle are free software as well; you can
redistribute them and/or modify them under the terms of the GNU
General Public License version 3 as published by the Free Software
Foundation.

The programs are distributed in the hope that they will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-
1301, USA. For further details please refer to:
http://www.gnu.org/licenses/gpl-3.0.html

'/

'' compile by
''   ./build

#DEFINE __PRUIO_COMPILING__

'* Driver header file.
#INCLUDE ONCE "pruio.bi"
'* Header file with convenience macros.
#INCLUDE ONCE "pruio_pins.bi"
'* Header file with PRU initialisation instructions.
#INCLUDE ONCE "pruio_init.bi"
'* Header file with PRU driver instructions.
#INCLUDE ONCE "pruio_run.bi"
'* Header file with PRU destructor instructions.
#INCLUDE ONCE "pruio_exit.bi"

'* Macro to calculate the total size of an array in bytes.
#DEFINE ArrayBytes(_A_) (UBOUND(_A_) + 1) * SIZEOF(_A_)

'* Declaration for C runtime function memcpy().
DECLARE FUNCTION memcpy CDECL ALIAS "memcpy"(BYVAL AS ANY PTR, BYVAL AS ANY PTR, BYVAL AS size_t) AS ANY PTR


/'* \brief Constructor, initialize devices, create default configuration.
\param Av avaraging for default steps (0 to 16, defaults to 0)
\param OpD open delay for default steps (0 to 0x3FFFF, defaults to 0x98)
\param SaD sample delay for default steps (0 to 255, defaults to 0)
\param Pru number of PRU subsystem to use (0 or 1, defaults to 1)

The constructor tries to open the PRUSS interrupt and reports an error
in case of a failure (the structure should be freed in that case and in
case of any other error).

Otherwise the constructor generates valid steps configuration data for
all channels (AIN0 to AIN 7 in steps 1 to 8). For these steps, the
default values can get customized using the (optional) parameter list:

- avaraging may get done in a certain number of steps, options are 1,
  2, 4, 8 or 16. (A non-matching parameter get increased either to the
  next higher or to the last option.)
- open delay is the number of clock cycles the ADC waits between
  setting the step configuration and sending the start of conversion
  signal.
- sample delay is the number of clock cycles the ADC waits before
  starting (the width of the start of conversion signal). It specifies
  the number of clock cycles between the single conversion processes.

See \ArmRef{12} for details on step configuration.

Also, and after executing the constructor, the step configuration can
get customized by function \ref PruIo::adc_step().

'/
CONSTRUCTOR PruIo( _
    BYVAL  Av AS uint8  = PRUIO_DEF_AVRAGE _
  , BYVAL OpD AS uint32 = PRUIO_DEF_ODELAY _
  , BYVAL SaD AS uint8  = PRUIO_DEF_SDELAY _
  , BYVAL Pru AS uint8  = PRUIO_DEF_PRUSS)

  SELECT CASE AS CONST Pru
  CASE 0
    PruEvtout = PRU_EVTOUT_0
    PruIRam = PRUSS0_PRU0_IRAM
    PruDRam = PRUSS0_PRU0_DATARAM
    ArmPruInt = ARM_PRU0_INTERRUPT
  CASE 1
    PruEvtout = PRU_EVTOUT_1
    PruIRam = PRUSS0_PRU1_IRAM
    PruDRam = PRUSS0_PRU1_DATARAM
    ArmPruInt = ARM_PRU1_INTERRUPT
  CASE ELSE : Errr = @"unknown PRUSS - select 0 or 1" : EXIT CONSTRUCTOR
  END SELECT
  PruNo = Pru
  prussdrv_init()

  IF prussdrv_open(PRUIO_EVNT) THEN _  '             open PRU Interrupt
              Errr = @"failed opening uio5 interrupt" : EXIT CONSTRUCTOR

  prussdrv_map_prumem(PruDRam, CAST(ANY PTR, @DRam))
  prussdrv_map_extmem(@ERam)
  ESize = prussdrv_extmem_size()
  EOffs = prussdrv_get_phys_addr(ERam)

  VAR o = PRUIO_GPIO_OFFS SHR 2 _
    , l = SIZEOF(GpioSet) * (PRUIO_GPIO_AZ + 1)
  Gpio = CAST(GpioSet PTR, DRam + o)
  IF 0 >= prussdrv_pru_write_memory(PruDRam, o, CAST(uint32 PTR, @GpioInit(0)), l) THEN _
         Errr = @"failed loading GPIO initialisation" : EXIT CONSTRUCTOR

  prussdrv_pru_disable(PruNo) '                              disable PRU
  l = ArrayBytes(Pru_Init)
  IF 0 >= prussdrv_pru_write_memory(PruIRam, 0, @Pru_Init(0), l) THEN _
       Errr = @"failed loading Pru_Init instructions" : EXIT CONSTRUCTOR
  prussdrv_pruintc_init(@IntcInit) '           get interrupt initialized
  prussdrv_pru_enable(PruNo)

  VAR a = ABS((Av > 1) + (Av > 2) + (Av > 4) + (Av > 8)) SHL 2 _
    , d = OpD AND &h3FFFF
  FOR i AS INTEGER = 1 TO 8
    WITH St_p(i)
      .Confg = a + ((i - 1) SHL 19)
      .Delay = d + SaD SHL 24
    END WITH
  NEXT

  prussdrv_pru_wait_event(PRUIO_EVNT)
  IF DRam[0] <> PRUIO_MSG_INIT_OK THEN _
     Errr = @"failed executing Pru_Init instructions" : EXIT CONSTRUCTOR

  BallConf = CAST(uint8 PTR, DRam) + PRUIO_BALL_OFFS
  VAR p1 = DRam[1] - PRUIO_BALL_OFFS _
    , p2 = p1 + (PRUIO_GPIO_AZ + 1) * PRUIO_GPIO_DATA _
   , adc = DRam + p1 + p2
  CSize = p2 + iif(adc[0], PRUIO_ADC_DATA, PRUIO_ADC_EMPTY)
  BallOrg = ALLOCATE(CSize)
  IF 0 = BallOrg THEN         Errr = @"out of memory" : EXIT CONSTRUCTOR
  memcpy(BallOrg, BallConf, CSize)
  AdcOrg = BallOrg + p2
  GpioOrg = BallOrg + p1

  BallRef = BallConf + PRUIO_BALL_AZ + 1
  FOR i AS INTEGER = 0 TO PRUIO_BALL_AZ '                  lock all pins
    BallRef[i] = 255
    IF BIT(BallConf[i], 5) THEN CONTINUE FOR '          skip input balls
    VAR y = BallGpio(i) '        ... or set GPIO OE register for outputs
    Gpio[y SHR 5 AND &b11].OutE AND= NOT (1 SHL (y AND &b11111))
  NEXT
  FOR i AS INTEGER = 0 TO UBOUND(P8_Pins) '     unlock P8 pins in mode 7
    VAR x = P8_Pins(i)
    IF (BallConf[x] AND &b111) = 7 THEN BallRef[x] = BallGpio(x)
  NEXT
  FOR i AS INTEGER = 0 TO UBOUND(P9_Pins) '     unlock P9 pins in mode 7
    VAR x = P9_Pins(i)
    IF (BallConf[x] AND &b111) = 7 THEN BallRef[x] = BallGpio(x)
  NEXT
END CONSTRUCTOR


/'* \brief Destructor to restore configurations and clear memory.

The destructor copies the original configuration to DRam (if any),
loads new instructions to the PRU and start them. This PRU code
restores the devices GPIOs, Control Module and ADC to their original
configurations. Finaly the PRU gets powered off and the memory of the
PruIo instance get freed.

The destructor cannot report error messages in member variable \ref
PruIo::Errr. Messages (if any) get sent directly to the ERROUT pipe of
the operating system instead.

'/
DESTRUCTOR PruIo()
  prussdrv_pru_disable(PruNo)

  IF BallOrg THEN
    memcpy(BallConf, BallOrg, CSize)
    DEALLOCATE(BallOrg)
    DRam[1] = PRUIO_BALL_OFFS
  ELSE
    DRam[1] = 0
  END IF
  Errr = 0

  VAR l = ArrayBytes(Pru_Exit)
  IF 0 >= prussdrv_pru_write_memory(PruIRam, 0, @Pru_Exit(0), l) THEN
    Errr = @"failed loading Pru_Exit instructions"
  ELSE
    prussdrv_pruintc_init(@IntcInit) '         get interrupt initialized
    prussdrv_pru_enable(PruNo)
    prussdrv_pru_wait_event(PRUIO_EVNT)
    IF DRam[0] <> PRUIO_MSG_EXIT_OK THEN _
      Errr = @"failed executing Pru_Exit instructions"
  END IF
  IF Errr THEN l = FREEFILE : OPEN ERR AS l : PRINT #l, *Errr : CLOSE #l

  prussdrv_pru_disable(PruNo)
  prussdrv_exit() '                                       power down PRU
END DESTRUCTOR


/'* \brief Load configuration from host (ARM) to driver (PRU).
\param Samp number of samples to fetch (defaults to zero)
\param Mask mask for active steps (defaults to all 8 channels active in steps 1 to 8)
\param Tmr timer value in [ns] to specify the sampling rate (defaults to zero, MM only)
\param Mds modus for output (defaults to 4 = 16 bit)
\param ClDv divisor for ADC input clock (defaults to 0 = full speed = 2.4 MHz)
\returns zero on success (otherwise a string with an error message)

This function is used to download the configuration from the host (ARM)
to the driver (PRU). The PRU gets stopped (if running) and the new
configurations get loaded. Also the PRU instructions get
re-initialized.

In case of an error the PRU will be disabled after this call. Otherwise
it's running and

- waits for a call to \ref PruIo::mm_start() (in case of Samp > 1) or
- starts sampling and feading values to \ref PruIo::Value otherwise.

The *Samp* parameter specifies the number of samples to convert for
each channel. In single mode (Samp <= 1 = default) sampling starts
immediately and the index in the array \ref PruIo::Value[] is equal to
the step number. Inactive steps return 0 (zero) in this case.

| field    | result of   | defaults to   |
| -------: | :---------: | :------------ |
| Value[0] | charge step | allways zero  |
| Value[1] | step 1      | AIN0          |
| Value[2] | step 2      | AIN1          |
| ...      | ...         | ...           |

In MM (Samp > 1) the array \ref PruIo::Value[] contains no zero values.
Instead only values from active steps get collected. The charge step
(step 0) returns no value. So when 3 steps are active in the Mask and
Samp is set to 5, a total of 3 times 5 = 15 values get available in the
array \ref PruIo::Value[] (after the call of the function \ref
PruIo::mm_start() ). The array contains the active steps, so when ie.
steps 3, 6 and 7 are active in the Mask, the array contains:

| field    | Mask = &b110010000 |
| -------: | :----------------- |
| Value[0] | 1. sample AIN3     |
| Value[1] | 1. sample AIN6     |
| Value[2] | 1. sample AIN7     |
| Value[3] | 2. sample AIN3     |
| Value[4] | 2. sample AIN6     |
| Value[5] | 2. sample AIN7     |
| Value[6] | 3. sample AIN3     |
| Value[7] | 3. sample AIN6     |
| Value[8] | ...                |

Currently the number of samples is limited by the external memory
allocated by the kernel PRUSS driver. This 256 kByte by default, see
\ref ChaMemory for further informations.

| active Steps | max. Samples |
| -----------: | :----------- |
|            1 | 131072       |
|            2 | 65536        |
|            3 | 43690        |
|            4 | 32768        |
|            5 | 26214        |
|            6 | 21845        |
|            7 | 18724        |
|            8 | 16384        |
|          ... |   ...        |

The *Mask* parameter specifies the active steps. Setting a bit in the
Mask activates a step defined by the step configuration (by default
bits 1 = AIN0, 2 = AIN1, ... up to 8 = AIN7 are set, use function \ref
PruIo::adc_step() to customize steps).

\note Bit 0 controls the charge step (see \ArmRef{12}, ADC STEPENABLE
register).

The highest bit 31 has a special meaning for customizing the idle step.
By default the idle configuration is set like the configuration of the
first active step, so that (in MM) the open delay can get
reduced to a minimum for that step (if there's enough time left before
restart the ADC). By setting bit 31 the configuration from \ref
PruIo::St_p is used instead.

The *Tmr* parameter specifies the sampling rate. It's the number of
nano seconds between the starts of the ADC sampling process. The IEP
timer gets used. It is configured to increase by steps of 5 (it counts
in GHz, but runs at 200 MHz), so values like 22676 or 22679 results to
the same frequency. Some examples

| Tmr [ns] | Sampling rate [Hz] |
| -------: | :----------------- |
| 1e9      | 1                  |
| 1e6      | 1000               |
| 22675    | ~44100             |

\note This value has no effect in single mode (when Samp is less than 2).

The *Mds* parameter specifies the range of the samples. By default (Mds
= 4) the 12 bit samples from the ADC get left shifted by 4, so that
they actually are 16 bit values and can get compared with samples from
other ADC devices (like 16 bit audio data). Examples

| Mds      | samples  |
| -------: | :------- |
| 0        | 12 bit   |
| 1        | 13 bit   |
| 2        | 14 bit   |
| 3        | 15 bit   |
| 4        | 16 bit   |
| >4       | 16 bit   |

The *ClDv* parameter gets transfered to the ADC clock divider register
ADC_CLKDIV (&h4C). The default value (0 = zero) lets the analog front
end (AFE) running at full speed (2.4 MHz). Otherwise the clock
frequency gets divided by this value + 1. Some examples

| ClDv | AFE [MHz] |
| ---: | :-------- |
| 0    | 2.4       |
| 1    | 1.2       |
| 5    | 0.4       |

Furthermore the registers \ref PruIo::AdcReg24 to \ref PruIo::AdcReg40
(ie. IRQ and DMA settings) get transfered to the ADC device, but bits 0
to 2 from \ref PruIo::AdcReg40 are controled by the driver software.
See \ArmRef{12} for details on ADC configurations.

'/
FUNCTION PruIo.config CDECL( _
    BYVAL Samp AS uint32 = PRUIO_DEF_SAMPLS _
  , BYVAL Mask AS uint32 = PRUIO_DEF_STPMSK _
  , BYVAL  Tmr AS uint32 = PRUIO_DEF_TIMERV _
  , BYVAL  Mds AS uint16 = PRUIO_DEF_LSLMOD _
  , BYVAL ClDv AS uint16 = PRUIO_DEF_CLKDIV) AS ZSTRING PTR
  prussdrv_pru_disable(PruNo) '                              disable PRU

  VAR c = UBOUND(St_p), r = 0, n = 0, d = 0
  FOR i AS INTEGER = c - 1 TO 0 STEP -1
    IF BIT(Mask, i) THEN
      r = i '                                        find right-most bit
      n += 1 '                                               count steps
      WITH St_p(r) '                      calculate clock cycles (delay)
        VAR opd = .Delay AND &h3FFFF _
          , smd = .Delay SHR 24 _
          , avr = (.Confg SHR 2) AND &b111
        d += opd + 1 + (14 + smd) * IIF(avr, 1 SHL avr, 1)
      END WITH
    END IF
  NEXT
  IF r < 1 THEN                   Errr = @"no step active" : RETURN Errr

  IF Samp < 2 THEN
    Samples = 0
    TimerVal = 0
    Value = CAST(uint16 PTR, CAST(ANY PTR, DRam) + PRUIO_ADC_BUFF) - 1
  ELSE
    Samples = Samp * n
    IF (Samples SHL 1) > ESize THEN _
                                   Errr = @"out of memory" : RETURN Errr
    d *= (ClDv + 1) * 417 '    417 ~= 1000000 / 2400 (= 1 GHz / 2.4 MHz)
    d += 30 '                               PRU cycles for restart [GHz]
    IF Tmr <= d THEN         Errr = @"sample rate too big" : RETURN Errr
    TimerVal = Tmr
    Value = CAST(uint16 PTR, ERam)
  END IF
  ChAz = n
  StepMask = Mask AND ((1 SHL c) - 1)
  ClockDiv = ClDv
  LslMode = IIF(Mds < 4, Mds, CAST(uint16, 4))
  St_p(c).Delay = IIF(BIT(Mask, 31), r, 0) '     adapt idle step config?

  c = PRUIO_ADC_OFFS SHR 2
  r = OFFSETOF(PruIo, DRam)
  IF 0 >= prussdrv_pru_write_memory(PruDRam, c, @Samples, r) THEN _
                       Errr = @"failed loading parameters" : RETURN Errr

  r = ArrayBytes(Pru_Run)
  IF 0 >= prussdrv_pru_write_memory(PruIRam, 0, @Pru_Run(0), r) THEN _
             Errr = @"failed loading Pru_Run instructions" : RETURN Errr
  prussdrv_pruintc_init(@IntcInit) '           get interrupt initialized
  prussdrv_pru_enable(PruNo)

  c = IIF(Samp < 2, PRUIO_MSG_IO_OK, PRUIO_MSG_MM_WAIT)
  prussdrv_pru_wait_event(PRUIO_EVNT)
  IF DRam[0] <> c THEN _
           Errr = @"failed executing Pru_Run instructions" : RETURN Errr

  IF Samp < 2 THEN RETURN 0

  prussdrv_pru_clear_event(PRUIO_EVNT, PRUIO_IRPT)
  prussdrv_pru_send_event(ArmPruInt) '                prepare fast start
  RETURN 0
END FUNCTION


/'* \brief Customize a single configuration step.
\param Stp step index (0 = step 0 => charge step, 1 = step 1 (=> AIN0 by default),  ..., 17 = idle step)
\param ChN channel number to scan (0 = AIN0, 1 = AIN1, ...)
\param Av new value for avaraging (defaults to 4)
\param SaD new value for sample delay (defaults to 0)
\param OpD new value for open delay (defaults to 0x98)
\returns zero on success (otherwise a string with an error message)

This function is used to adapt a step configuration. In the
constructor, steps 1 to 8 get configured for AIN0 to AIN7 (other steps
stay un-configured). By this function you can customize the default
settings and / or configure further steps (input channel number,
avaraging and delay values).

|      Stp | Description |
| -------: | :---------- |
| 0        | charge step |
| 1        | step 1      |
| 2        | step 2      |
| ...      | ...         |
| 17       | idle step   |

\note This sets the local data on the host system (ARM). The setup gets
      uploaded to the PRU and activated when calling function \ref
      PruIo::config().

It's also possible to directly write to the step configuration in
member variables \ref PruIo::St_p (i).Confg and \ref
PruIo::St_p (i).Delay. See \ArmRef{12} for details on ADC
configurations.

'/
FUNCTION PruIo.adc_step CDECL( _
    BYVAL Stp AS uint8 _
  , BYVAL ChN AS uint8 _
  , BYVAL  Av AS uint8  = PRUIO_DEF_AVRAGE _
  , BYVAL SaD AS uint8  = PRUIO_DEF_SDELAY _
  , BYVAL OpD AS uint32 = PRUIO_DEF_ODELAY) AS ZSTRING PTR

  IF Stp > UBOUND(St_p) THEN Errr = @"step number too big" : RETURN Errr
  IF ChN > 7 THEN         Errr = @"channel number too big" : RETURN Errr

  WITH St_p(Stp)
    VAR a = ABS((Av > 1) + (Av > 2) + (Av > 4) + (Av > 8))
    .Confg = (a SHL 2) + (ChN SHL 19)
    .Delay = (OpD AND &h3FFFF) + (SaD SHL 24)
  END WITH : RETURN 0
END FUNCTION


'* macro to check a CPU ball number (0 to 109 is valid range)
#DEFINE BallCheck(_T_,_R_) IF Ball > PRUIO_BALL_AZ THEN Errr = @"unknown" _T_ " pin number" : RETURN _R_

/'* \brief Create a text description for a pin configuration.
\param Ball the CPU ball number to describe
\returns a human-readable text string (internal string, never free it)

This function is used to create a text description for the current
state of a CPU ball, that is called a pin when it's connected to one of
the Beaglebone headers P8 or P9.

The description contains the pin name and its mode. Header pin names
start with a capital 'P', CPU ball names start with a lower case 'b'.
The detailed pinmux setting is only described for pins in mode 7 (GPIO
mode). Otherwise only the mode number gets shown. Finally locked pins
get marked by the text '(locked)'.

The returned string pointer points to an internal string. Never free
it. The string gets overwritten on further calls to this function, so
make local copies if you need several descriptions at a time. The
string may contain an error message if the ball number is too big.

'/
FUNCTION PruIo.gpio_get_config CDECL(BYVAL Ball AS uint8) AS ZSTRING PTR
  STATIC AS STRING*50 t

  SELECT CASE AS CONST Ball '                                  find name
  CASE   6 : t = "P8_03"
  CASE   7 : t = "P8_04"
  CASE   2 : t = "P8_05"
  CASE   3 : t = "P8_06"
  CASE  36 : t = "P8_07"
  CASE  37 : t = "P8_08"
  CASE  39 : t = "P8_09"
  CASE  38 : t = "P8_10"
  CASE  13 : t = "P8_11"
  CASE  12 : t = "P8_12"
  CASE   9 : t = "P8_13"
  CASE  10 : t = "P8_14"
  CASE  15 : t = "P8_15"
  CASE  14 : t = "P8_16"
  CASE  11 : t = "P8_17"
  CASE  35 : t = "P8_18"
  CASE   8 : t = "P8_19"
  CASE  33 : t = "P8_20"
  CASE  32 : t = "P8_21"
  CASE   5 : t = "P8_22"
  CASE   4 : t = "P8_23"
  CASE   1 : t = "P8_24"
  CASE   0 : t = "P8_25"
  CASE  31 : t = "P8_26"
  CASE  56 : t = "P8_27"
  CASE  58 : t = "P8_28"
  CASE  57 : t = "P8_29"
  CASE  59 : t = "P8_30"
  CASE  54 : t = "P8_31"
  CASE  55 : t = "P8_32"
  CASE  53 : t = "P8_33"
  CASE  51 : t = "P8_34"
  CASE  52 : t = "P8_35"
  CASE  50 : t = "P8_36"
  CASE  48 : t = "P8_37"
  CASE  49 : t = "P8_38"
  CASE  46 : t = "P8_39"
  CASE  47 : t = "P8_40"
  CASE  44 : t = "P8_41"
  CASE  45 : t = "P8_42"
  CASE  42 : t = "P8_43"
  CASE  43 : t = "P8_44"
  CASE  40 : t = "P8_45"
  CASE  41 : t = "P8_46"
  CASE  28 : t = "P9_11"
  CASE  30 : t = "P9_12"
  CASE  29 : t = "P9_13"
  CASE  18 : t = "P9_14"
  CASE  16 : t = "P9_15"
  CASE  19 : t = "P9_16"
  CASE  87 : t = "P9_17"
  CASE  86 : t = "P9_18"
  CASE  95 : t = "P9_19"
  CASE  94 : t = "P9_20"
  CASE  85 : t = "P9_21"
  CASE  84 : t = "P9_22"
  CASE  17 : t = "P9_23"
  CASE  97 : t = "P9_24"
  CASE 107 : t = "P9_25"
  CASE  96 : t = "P9_26"
  CASE 105 : t = "P9_27"
  CASE 103 : t = "P9_28"
  CASE 101 : t = "P9_29"
  CASE 102 : t = "P9_30"
  CASE 100 : t = "P9_31"
  CASE 109 : t = "P9_41"
  CASE  89 : t = "P9_42"
  CASE ELSE
    BallCheck("", Errr)
    t = "b " & RIGHT("00" & Ball, 3)
  END SELECT

  VAR r = BallConf[Ball], m = r AND &b111, g = BallGpio(Ball) SHR 5
  IF m = 7 THEN
    t &= ", GPIO " & g & "/" & RIGHT("0" & (BallGpio(Ball) AND 31), 2)
    t &= *IIF(BIT(r, 5), @": input", @": output")
    IF BIT(r, 3) THEN
      t &= ", nopull"
    ELSE
      IF BIT(r, 4) THEN t &= ", pullup" ELSE t &= ", pulldown"
    END IF
  ELSE
    t &= ", mode " & m
  END IF
  IF BallRef[Ball] = 255 THEN t &= " (locked)"
  RETURN SADD(t)
END FUNCTION



/'* \brief Set the configuration of a GPIO.
\param Ball the CPU ball number to set
\param Modus the mode for the GPIO
\param Lokk the locking specification
\returns zero on success (otherwise a pionter to an error message)

This function is used to configure a digital pin. Use the macros
defined in pruio.bi to specify the pin number for a pin on the
Beaglebone headers (ie P8_03 selects pin 3 on header P8).

Its also possible to get the state of a CPU ball (not connected to
a header). In this case you need to find the matching CPU ball number
and pass it in as the parameter Ball.

Parameter Modus specifies the pinmux mode for the ARM control module
(see \ArmRef{9}). By default the pin gets configured as input pin
with pullup resistor, so you can connect a button between the pin and
ground to use it as a on/off switch. Other configurations are prepared
as macros:

| macro name      | Description                              |
| --------------: | :--------------------------------------- |
| PRUIO_IN        | open input pin (no resistor)             |
| PRUIO_IN_0      | low input pin (with pulldown resistor)   |
| PRUIO_IN_1      | high input pin (with pullup resistor)    |
| PRUIO_OUT0      | output pin set to low (no resistor)      |
| PRUIO_OUT1      | output pin set to high (no resistor)     |
| PRUIO_PIN_RESET | reset pin configuration to initial state |

By default only unlocked pins can get changed. These are header pins on
P8 or P9 headers that were in mode 7 (GPIO) at start-up. All other pins
are locked. That are internal pins not connected to a header and pins
in a different mode (ie HDMI or EMMC2 pins).

Parameter Lokk can be specified to change the locking mode of a pin.
Use the enumerator from \ref PRUIO_PIN_LOCKING to specify the new mode
(the latest is the default value):

| enumerator name   | Description                                               |
| ----------------: | :-------------------------------------------------------- |
| PRUIO_UNLOCK_CURR | unlock a pin, don't change the configuration              |
| PRUIO_UNLOCK_ORIG | unlock a pin, change to original (initial) configuration  |
| PRUIO_UNLOCK_NEW  | unlock a pin, change to parameter configuration           |
| PRUIO_LOCK_CURR   | lock a pin, don't change the configuration                |
| PRUIO_LOCK_ORIG   | lock a pin, change to original (initial) configuration    |
| PRUIO_LOCK_NEW    | lock a pin, change to parameter configuration             |
| PRUIO_LOCK_CHECK  | don't change pin locking, skip operation if pin is locked |

\note Pin locking only works for function family PruIo::gpio_xxx(). It
      doesn't work in case of direct access to internal \ref PruIo::Gpio
      member variables.

'/
FUNCTION PruIo.gpio_set CDECL( _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8 = PRUIO_IN_0 _
  , BYVAL Lokk AS uint8 = PRUIO_LOCK_CHECK) AS ZSTRING PTR

  BallCheck("", Errr)

  SELECT CASE AS CONST Lokk
  CASE PRUIO_UNLOCK_CURR
    BallRef[Ball] = BallGpio(Ball) :                            RETURN 0
  CASE PRUIO_LOCK_CURR
    BallRef[Ball] = 255 :                                       RETURN 0
  CASE PRUIO_UNLOCK_ORIG
    BallConf[Ball] = PEEK(BallOrg + Ball)
    BallRef[Ball] = BallGpio(Ball)
  CASE PRUIO_LOCK_ORIG
    BallConf[Ball] = PEEK(BallOrg + Ball)
    BallRef[Ball] = 255
  CASE ELSE '                                             set new config
    SELECT CASE AS CONST Lokk
    CASE PRUIO_UNLOCK_NEW
      BallRef[Ball] = BallGpio(Ball)
    CASE PRUIO_LOCK_NEW
      BallRef[Ball] = 255
    CASE ELSE
      IF 255 = BallRef[Ball] THEN     Errr = @"pin locked" : RETURN Errr
    END SELECT

    VAR r = BallGpio(Ball)
    IF Modus = PRUIO_PIN_RESET THEN
      BallConf[Ball] = PEEK(BallOrg + Ball)
    ELSE
      BallConf[Ball] = Modus AND &b1111111
      IF BIT(Modus, 5) THEN '                                 input Ball
        Gpio[r SHR 5].OutE OR= 1 SHL (r AND 31)
      ELSE '                                                 output Ball
        Gpio[r SHR 5].OutE AND= NOT (1 SHL (r AND 31))
        IF BIT(Modus, 7) THEN
          Gpio[r SHR 5].SetM OR= 1 SHL (r AND 31)
        ELSE
          Gpio[r SHR 5].ClrM OR= 1 SHL (r AND 31)
        END IF
      END IF
    END IF
  END SELECT

  IF DRam[0] <> PRUIO_MSG_IO_OK THEN RETURN 0
  WHILE DRam[1] <> PRUIO_MSG_INIT_OK : WEND : DRam[1] = Ball OR (1 SHL 31)
  RETURN 0
END FUNCTION


/'* \brief Get the state of a GPIO.
\param Ball the CPU ball number to test
\returns GPIO state (otherwise -1, check \ref PruIo::Errr for an error message)

This function is used to get the state of a digital pin (GPIO). Use the
macros defined in pruio.bi to specify the pin number for a pin on the
Beaglebone headers (ie P8_03 selects pin 3 on header P8).

It's also possible to get the state of a CPU ball (not connected to
a header). In this case you need to find the matching CPU ball number
and pass it in as the parameter Ball.

The function returns the state of input and output pins (locked or
unlocked). Return values are

| Value | Description                   |
| ----: | :---------------------------- |
| 1     | GPIO is in high state         |
| 0     | GPIO is in low state          |
| -1    | error (undefined ball number) |

An alternative (and faster) way to get a pin (or ball) state is reading
the corresponding bit in member variable \ref PruIo::Gpio[i].Stat.

'/
FUNCTION PruIo.gpio_get CDECL(BYVAL Ball AS uint8) AS uint32
  BallCheck("", -1)
  VAR r = BallRef[Ball]
  RETURN IIF(Gpio[r SHR 5].Stat AND (1 SHL (r AND 31)), 1, 0)
END FUNCTION


/'* \brief Set the state of a GPIO.
\param Ball the CPU ball number to test
\param Modus the state to set (0 = low, high otherwise)
\returns zero on success (otherwise a pointer to an error message)

This function is used to set the state of an output GPIO. Use the
macros defined in pruio.bi to specify the pin number for a pin on the
Beaglebone headers (ie P8_03 selects pin 3 on header P8).

Its also possible to set the state of a CPU ball (not connected to
a header). In this case you need to find the matching CPU ball number
and pass it in as the parameter Ball.

This function only works on unlocked output pins. Selecting an input
pin or a locked pin generates an error message.

An alternative (and faster) way to set a pin (or ball) state is writing
to the corresponding bit in member variables \ref PruIo::Gpio[i].SetM
or \ref PruIo::Gpio[i].ClrM. (No locking in this case, mind what you're
doing.)

'/
FUNCTION PruIo.gpio_out CDECL( _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8 = 0) AS ZSTRING PTR

  BallCheck(" output", Errr)
  IF BIT(BallConf[Ball], 5) THEN       Errr = @"input pin" : RETURN Errr
  VAR r = BallRef[Ball]
  IF r = 255 THEN              Errr = @"output pin locked" : RETURN Errr
  IF Modus THEN
    Gpio[r SHR 5].SetM OR= 1 SHL (r AND 31)
  ELSE
    Gpio[r SHR 5].ClrM OR= 1 SHL (r AND 31)
  END IF : RETURN 0
END FUNCTION


/'* \brief Create a trigger configuration for a digital trigger (GPIO).
\param Ball the CPU ball number to test
\param GpioV the state to check (defaults to high = 1)
\param Skip the number of samples to skip (defaults to 0 = zero, max. 1023)
\returns the trigger configuration (or zero in case of an error, check \ref PruIo::Errr)

This function is used to create a configuration for a digital (= GPIO)
trigger. Pass the returned value as parameter to function \ref
PruIo::mm_start(). The measurement (or the next trigger) will start
when the specified GPIO gets in to the declared state.

The parameter Skip can be used to hold up the start for a certain
time (previously defined by the Tmr parameter in the last call to
function \ref PruIo::config).

This trigger is a fast trigger. The ADC device is waiting in idle mode
while the GPIO gets checked.

'/
FUNCTION PruIo.mm_trg_pin CDECL( _
    BYVAL Ball AS uint8 _
  , BYVAL GpioV AS uint8 = 0 _
  , BYVAL Skip AS uint16 = 0) AS uint32

  BallCheck(" trigger", 0)
  IF 7 <> (BallConf[Ball] AND &b111) THEN _
                    Errr = @"pin must be in GPIO mode (mode 7)" : RETURN 0
  IF Skip > 1023 THEN         Errr = @"too much values to skip" : RETURN 0

  DIM AS uint32 r =     (1 SHL 21)    _ ' GPIO bit
        +            (Ball SHL  8)    _ ' Ball number
        + IIF(GpioV = 0, 1 SHL  7, 0) _ ' negative bit
        +               (1 SHL  4)      ' fast bit
  IF Skip THEN r +=     (1 SHL  5)    _ ' post trigger bit
                  +  (Skip SHL 22)      ' number of samples to skip
  RETURN r
END FUNCTION


/'* \brief Create a trigger configuration for an analog input trigger.
\param Stp the step number to use for trigger input
\param AdcV the sample value to match (positive check greater than, negative check less than)
\param Rela if AdcV is relative to the current input
\param Skip the number of samples to skip (defaults to 0 = zero, max. 1023)
\returns the trigger configuration (or zero in case of an error, check \ref PruIo::Errr)

This function is used to create a configuration for an analog (= AIN)
trigger. Pass the returned value as parameter to function \ref
PruIo::mm_start(). The measurement (or the next trigger) will start
when the specified analog input (AIN) gets in to the declared state.

The parameter AdcV specifies the value to compare with. A positive
value starts when the input is greater than AdcV. A negative value
starts when the input is less than AdcV.

AdcV is scalled like the samples, so when the previuos call to function
\ref PruIo::config() requires 16 bit samples (Mds = 4), AdcV has to be
specified as 16 bit value as well.

AdcV can either be an absolute value or a relative value. For the later
case set parameter Rela to any value <> zero. The driver will
fetch the current analog input value when the trigger gets active and
adds AdcV to calculate the absolute trigger value.

This trigger value gets auto-limited to a certain range (ie &hF0 to
&hFF00, in case of default 16 bit setting), to avoid trigger values
that never can be reached.

The parameter Skip can be used to hold up the start for a certain
time (previously defined by the Tmr parameter in the last call to
function \ref PruIo::config). Example:

~~~{.bas}
 Tmr = 1e8              ' 10 Hz
Skip = 500              ' skip 500 samples
time = Skip / Tmr * 1e9 ' delay time = 5 seconds (1e9 = Hz / GHz)
~~~

This trigger is a fast trigger. Only the specified step is active while
waiting for the event. The trigger step can be inactive in the Mask of
the previous call to function \ref PruIo::config() and only be used for
trigger purposes. (Ie. a short open delay can get specified for the
trigger step since there is no channel muxing.)

\note All error checks in this function are related to the parameters
      of the previuos call to function \ref PruIo::config(). The
      created specification may get invalid by changing the ADC
      settings by a further call to function \ref PruIo::config() with
      different parameters (ie. when the trigger step gets cleared). To
      be on the save side, re-create your trigger specifications after
      each call to function \ref PruIo::config().

'/
FUNCTION PruIo.mm_trg_ain CDECL( _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Rela AS uint8 = 0 _
  , BYVAL Skip AS uint16 = 0) AS uint32

  IF Stp < 1 ORELSE Stp > 16 THEN Errr = @"invalid step number" : RETURN 0
  IF 0 = St_p(Stp).Confg THEN _
                          Errr = @"trigger step not configured" : RETURN 0
  IF Skip > 1023 THEN         Errr = @"too much values to skip" : RETURN 0

  VAR v = ABS(AdcV) SHR LslMode
  IF v < &hF THEN v = &hF ELSE IF v > &hFF0 THEN v = &hFF0

  DIM AS uint32 r =      Stp - 1 _     ' step to watch
        + (              v SHL 8) _    ' sample AdcV to check
        + IIF(AdcV < 0,  1 SHL 7, 0) _ ' negative bit
        + IIF(Rela,      1 SHL 6, 0) _ ' relative bit
        + (              1 SHL 4)      ' fast bit
  IF Skip THEN r +=  (Skip SHL 22) _   ' number of samples to skip
                  +     (1 SHL 5)      ' post trigger bit
  RETURN r
END FUNCTION


/'* \brief Create a trigger configuration for an analog input trigger.
\param Stp the step number to use for trigger input
\param AdcV the sample value to match (positive check greater than, negative check less than)
\param Samp the number of samples for the pre-trigger
\param Rela if AdcV is relative to the current input
\returns the trigger configuration (or zero in case of an error, check \ref PruIo::Errr)

This function is used to create a configuration for an analog (= AIN)
pre-trigger. Pass the returned value as parameter to function \ref
PruIo::mm_start(). The measurement on all active steps will start
immediately and collect the input values in a ring buffer. Normal
measurement starts when the specified analog input (AIN) gets in to the
declared state.

Either a certain step (that must be activated in the previous call to
function \ref PruIo::config() ) can be checked. Or all active inputs
get checked against the specified AdcV. In the later case AdcV is
allways an absolute value (parameter Rela gets ignored).

The parameter AdcV specifies the value to compare with. A positive
value starts when the input is greater than AdcV. A negative value
starts when the input is less than AdcV.

AdcV is scalled like the samples, so when the previuos call to function
\ref PruIo::config() requires 16 bit samples (Mds = 4), AdcV has to be
specified as 16 bit value as well.

AdcV can either be an absolute value or a relative value. For the later
case set parameter Rela to any value <> zero. The driver will
fetch the current analog input value when the trigger gets active and
add AdcV to calculate the absolute trigger value.

The trigger value gets auto-limited to a certain range (ie &hF0 to
&hFF00, in case of default 16 bit setting), to avoid trigger values
that never can be reached.

Parameter Samp is used to specify the number of samples to fetch
before the trigger event occurs. It specifies the number of sampling
sets for all active channels. Its maximum value is limited to 1023 and
also by the amount of memory available (approx. 7000 samples in DRam0
and DRam1) to sort the ring buffer.

The pre-trigger is a slow trigger. The ADC device goes through all
activated steps while waiting for the trigger event.

\note All error checks in this function are related to the parameters
      of the previuos call to function \ref PruIo::config(). The
      created specification may get invalid by changing the ADC
      settings by a further call to function \ref PruIo::config() with
      different parameters (ie. when the trigger step gets cleared). To
      be on the save side, re-create your trigger specifications after
      each call to function \ref PruIo::config().

\note A pre-trigger is always the last trigger specification in the
      call to function \ref PruIo::mm_start() (all further
      specifications get ignored).

'/
FUNCTION PruIo.mm_trg_pre CDECL( _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Samp AS uint16 = 0 _
  , BYVAL Rela AS uint8 = 0) AS uint32

  IF Stp > 16                THEN Errr = @"invalid step number" : RETURN 0
  IF Stp andalso 0 = St_p(Stp).Confg THEN _
                          Errr = @"trigger step not configured" : RETURN 0
  IF Stp ANDALSO 0 = (StepMask AND (1 SHL Stp)) THEN _
                           Errr = @"trigger step not activated" : RETURN 0
  VAR t = (Samp + 1) * ChAz
  IF t > ((16384 - PRUIO_ADC_OFFS) SHR 1) THEN _
                                 Errr = @"too much pre-samples" : RETURN 0
  IF t > Samples THEN   Errr = @"more pre-samples than samples" : RETURN 0

  VAR v = ABS(AdcV) SHR LslMode
  IF v < &hF THEN v = &hF ELSE IF v > &hFF0 THEN v = &hFF0

  DIM AS uint32 r = (Samp SHL 22)  _ ' number of pre-samples
        +              (v SHL  8)  _ ' sample AdcV to check
        + IIF(AdcV < 0, 1 SHL  7, 0) ' negative bit
  IF 0 = Stp THEN r += (1 SHL 20)  _ ' all step bit,
             ELSE r +=  Stp -  1   _ ' or simple step number
        +     IIF(Rela, 1 SHL  6, 0) ' relative bit
  RETURN r
END FUNCTION


/'* \brief Start a measurement in MM.
\param Trg1 settings for first trigger (default = no trigger)
\param Trg2 settings for second trigger (default = no trigger)
\param Trg3 settings for third trigger (default = no trigger)
\param Trg4 settings for fourth trigger (default = no trigger)
\returns zero on success (otherwise a string with an error message)

This function starts a measurement in MM mode. The ADC configuration
from the previous call to function \ref PruIo::config() are used. The
measurement either starts immediately or the start gets controlled by
one (or up to four) trigger event(s).

Function are available to create trigger specifications:

- \ref PruIo::mm_trg_pin() for digital lines
- \ref PruIo::mm_trg_ain() for analog lines
- \ref PruIo::mm_trg_pre() for pre-triggers on analog lines

\note The created analog trigger specifications may get invalid by
      changing the ADC settings in a further call to function \ref
      PruIo::config() with different parameters (ie. when the trigger
      step gets cleared). To be on the save side, re-create your
      trigger specifications after each call to function \ref
      PruIo::config().

'/
FUNCTION PruIo.mm_start CDECL( _
    BYVAL Trg1 AS uint32 = 0 _
  , BYVAL Trg2 AS uint32 = 0 _
  , BYVAL Trg3 AS uint32 = 0 _
  , BYVAL Trg4 AS uint32 = 0) AS ZSTRING PTR

  IF DRam[0] <> PRUIO_MSG_MM_WAIT THEN _
                      Errr = @"measurement mode not ready" : RETURN Errr

  STATIC AS uint32 tmin = (1 SHL 22), t_pin
  DRam[3] = 0

#DEFINE PRUIO_PRE_TRIG(_T_) Trg##_T_ >= tmin ANDALSO 0 = (Trg##_T_ AND (1 SHL 4)) THEN : _
  IF BIT(Trg##_T_, 20) ORELSE BIT(StepMask, (Trg##_T_ AND &b1111) + 1) THEN : _
    VAR n = (Trg##_T_ SHR 22) * ChAz : _
    IF n < Samples THEN : DRam[3] = n SHL 1 : _
    ELSE :        Errr = @"Trg" #_T_ ": too much pre-trigger samples" : RETURN Errr : _
    END IF : _
  ELSE :       Errr = @"Trg" #_T_ ": pre-trigger step must be active" : RETURN Errr : _
  END IF

#DEFINE PRUIO_GPIO_TRIG(_T_) BIT(Trg##_T_, 21) THEN : _
    t_pin = (Trg##_T_ SHR 8) AND &b1111111 : _
    IF t_pin > PRUIO_BALL_AZ THEN _
                    Errr = @"Trg" #_T_ ": unknown trigger pin number" : RETURN Errr : _
    END IF : _
    IF BallConf[t_pin] AND &b111 <> 7 THEN _
          Errr = @"Trg" #_T_ ": trigger pin must be in mode 7 (GPIO)" : RETURN Errr : _
    ELSE Trg##_T_ AND= &b11111111111100000000000011111111uL : _
         Trg##_T_  OR= BallGpio(t_pin) SHL 8 : _
    END IF : _
  END IF

  IF Trg1 THEN
    IF PRUIO_PRE_TRIG(1)
    ELSE
      IF PRUIO_GPIO_TRIG(1)
      IF Trg2 THEN
        IF PRUIO_PRE_TRIG(2)
        ELSE
          IF PRUIO_GPIO_TRIG(2)
          IF Trg3 THEN
            IF PRUIO_PRE_TRIG(3)
            ELSE
              IF PRUIO_GPIO_TRIG(3)
              IF Trg4 THEN
                IF PRUIO_PRE_TRIG(4)
                ELSE
                  IF PRUIO_GPIO_TRIG(4)
                END IF
              END IF
            END IF
          END IF
        END IF
      END IF
    END IF
  END IF

  DRam[1] = ESize '                   note: index for PRUIO_TRG_PARA = 4
  DRam[2] = EOffs
  DRam[4] = Trg1
  DRam[5] = Trg2
  DRam[6] = Trg3
  DRam[7] = Trg4

  prussdrv_pru_clear_event(PruEvtout, ArmPruInt) '             off we go

  prussdrv_pru_wait_event(PRUIO_EVNT) '      wait for end of measurement
  prussdrv_pru_clear_event(PRUIO_EVNT, PRUIO_IRPT) '     clear interrupt
  prussdrv_pru_send_event(ArmPruInt) '                prepare next start
  RETURN 0
END FUNCTION
