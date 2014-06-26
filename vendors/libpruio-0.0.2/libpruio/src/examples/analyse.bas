/'* \file analyse.bas
\brief Example: analyse the devices configurations.

This file contains an example on how to use libpruio to read the
original configuration of the devices. It creates a PruIo structure
containing the initial data and then prints out in a human-readable
form.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all analyse.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"
'* include the convenience macros for header pins
#INCLUDE ONCE "../pruio/pruio_pins.bi"

' *****  main  *****

VAR io = NEW PruIo '*< create a PruIo structure, wakeup devices

WITH *io
  IF .Errr THEN
    ?"initialisation failed (" & *.Errr & ")"
  ELSE
    FOR i AS INTEGER = 0 TO PRUIO_GPIO_AZ
      VAR x = i * (PRUIO_GPIO_DATA SHR 2)
      ?"GPIO" & i & " was ";
      IF .GpioOrg[x + 4] = 2 THEN
        ?"on"
        ?"    OE: " & BIN(.GpioOrg[x + 1], 32)
        ?"  INT0: " & BIN(.GpioOrg[x + 2], 32)
        ?"  INT1: " & BIN(.GpioOrg[x + 3], 32)
      ELSE
        ?"off, COUNT: " & .GpioOrg[x + 5]
      END IF
    NEXT

    ?"Unlocked Pins:"
    FOR i AS INTEGER = 0 TO PRUIO_BALL_AZ
      IF .BallRef[i] <> 255 THEN ?"  " & *.gpio_get_config(i)
    NEXT
    ?"Locked header Pins:"
    FOR i AS INTEGER = 0 TO UBOUND(P8_Pins)
      VAR b = P8_Pins(i)
      IF .BallRef[b] = 255 THEN ?"  " & *.gpio_get_config(b)
    NEXT
    FOR i AS INTEGER = 0 TO UBOUND(P9_Pins)
      VAR b = P9_Pins(i)
      IF .BallRef[b] = 255 THEN ?"  " & *.gpio_get_config(b)
    NEXT

    IF .AdcOrg[0] THEN
      ?"ADC was on"
      ?"        REVISION: &h" & HEX(.AdcOrg[ 0], 8)
      ?"       SYSCONFIG: &b" & BIN(.AdcOrg[ 4], 4)
      ?"  IRQ_STATUS_RAW: &b" & BIN(.AdcOrg[ 9], 10)
      ?"      IRQ_STATUS: &b" & BIN(.AdcOrg[10], 10)
      ?"   IRQENABLE_SET: &b" & BIN(.AdcOrg[11], 10)
      ?"   IRQENABLE_CLR: &b" & BIN(.AdcOrg[12], 10)
      ?"       IRQWAKEUP: &b" & BIN(.AdcOrg[13], 1)
      ?"   DMAENABLE_SET: &b" & BIN(.AdcOrg[14], 2)
      ?"   DMAENABLE_CLR: &b" & BIN(.AdcOrg[15], 2)
      ?"            CRTL: &b" & BIN(.AdcOrg[16], 2)
      ?"         ADCSTAT: &b" & BIN(.AdcOrg[17], 8)
      ?"        ADCRANGE: &h" & HEX(.AdcOrg[18], 8)
      ?"      ADC_CLKDIV: &h" & HEX(.AdcOrg[19], 4)
      ?"        ADC_MISC: &b" & BIN(.AdcOrg[20], 8)
      ?"  Steps:            config  ,   delay"
      ?"       idle step: &h" & HEX(.AdcOrg[22], 8)
      ?"     charge step: &h" & HEX(.AdcOrg[23], 8) & ", &h" & HEX(.AdcOrg[24], 8)
      FOR i AS INTEGER = 1 TO 16
        VAR x = 23 + 2 * i
        ?"          step" & RIGHT("0" & i, 2) _
                   & ": &h" & HEX(.AdcOrg[x], 8) & ", &h" & HEX(.AdcOrg[x + 1], 8)
      NEXT
    ELSE
      ?"ADC was off"
      ?"      REVISION: " & HEX(.AdcOrg[1], 8)
      ?"  wakeup-count: " & HEX(.AdcOrg[2], 8)
    END IF
  END IF
END WITH

DELETE io '                    reset ADC, PinMux and GPIOs, clear memory
