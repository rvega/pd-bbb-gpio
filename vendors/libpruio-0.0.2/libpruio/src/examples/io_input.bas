/'* \file io_input.bas
\brief Example: print digital and analog inputs.

This file contains an example on how to use libpruio to print out the
state of the digital GPIOs and the analog input lines.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all io_input.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"


' *****  main  *****

VAR io = NEW PruIo '*< create a PruIo structure, wakeup devices

WITH *io
  DO '                                  pseudo loop, just to avoid GOTOs
    IF .Errr THEN    ?"initialisation failed (" & *.Errr & ")" : EXIT DO

'                  transfer default settings to PRU and start in IO mode
    IF .config() THEN        ?"config failed (" & *.Errr & ")" : EXIT DO

    ?"   .   |   .   |   .   |   .   |"
    ?:?:?:?:?
    VAR x = POS() _
      , y = CSRLIN() - 5
    DO '                           print current state (until keystroke)
      LOCATE y, x, 0
      ?BIN(.Gpio[0].Stat, 32) '                              GPIOs 0 - 3
      ?BIN(.Gpio[1].Stat, 32)
      ?BIN(.Gpio[2].Stat, 32)
      ?BIN(.Gpio[3].Stat, 32)
      ?HEX(.Value[1], 4) & " " & _ '                           AIN 0 - 7
       HEX(.Value[2], 4) & " " & _
       HEX(.Value[3], 4) & " " & _
       HEX(.Value[4], 4) & "  " & _
       HEX(.Value[5], 4) & " " & _
       HEX(.Value[6], 4) & " " & _
       HEX(.Value[7], 4) & " " & _
       HEX(.Value[8], 4);
    LOOP UNTIL LEN(INKEY())
    ?
  LOOP UNTIL 1
END WITH

DELETE io '                    reset ADC, PinMux and GPIOs, clear memory
