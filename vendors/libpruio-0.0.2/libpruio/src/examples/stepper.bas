/'* \file stepper.bas
\brief Example: control a stepper motor.

This file contains an example on how to use libpruio to control a
4-wire stepper motor:

- configure 4 pins as output
- receive user action in loop
- inform user about the current state
- change motor direction
- change motor speed
- stop holded or in power off mode
- move a single step (in holded mode)
- quit

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all stepper.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"
'* include the convenience macros for header pins
#INCLUDE ONCE "../pruio/pruio_pins.bi"

' output pins for the motor driver
#DEFINE P1 P8_08
#DEFINE P2 P8_10
#DEFINE P3 P8_12
#DEFINE P4 P8_14


/'* \brief make the motor move the next step.
\param Io pointer to PruIo structure
\param Rot direction of rotation (1 or -1)

This function sets 4 output pins for a stepper motor driver. It
remembers the last step as static variable (starting at 0 = zero) and
adds the new position to it. So the Rot parameter should either be 1 or
-1 to make the motor move one step in any direction.

'/
SUB move(BYVAL Io AS PruIo PTR, BYVAL Rot AS BYTE = 1)
  STATIC AS INTEGER p = 0

  WITH *Io
    p += Rot
    p AND= &b111

    SELECT CASE AS CONST p
    CASE 1    : .gpio_out(P1, 1) : .gpio_out(P2, 0) : .gpio_out(P3, 0) : .gpio_out(P4, 0)
    CASE 2    : .gpio_out(P1, 1) : .gpio_out(P2, 1) : .gpio_out(P3, 0) : .gpio_out(P4, 0)
    CASE 3    : .gpio_out(P1, 0) : .gpio_out(P2, 1) : .gpio_out(P3, 0) : .gpio_out(P4, 0)
    CASE 4    : .gpio_out(P1, 0) : .gpio_out(P2, 1) : .gpio_out(P3, 1) : .gpio_out(P4, 0)
    CASE 5    : .gpio_out(P1, 0) : .gpio_out(P2, 0) : .gpio_out(P3, 1) : .gpio_out(P4, 0)
    CASE 6    : .gpio_out(P1, 0) : .gpio_out(P2, 0) : .gpio_out(P3, 1) : .gpio_out(P4, 1)
    CASE 7    : .gpio_out(P1, 0) : .gpio_out(P2, 0) : .gpio_out(P3, 0) : .gpio_out(P4, 1)
    CASE ELSE : .gpio_out(P1, 1) : .gpio_out(P2, 0) : .gpio_out(P3, 0) : .gpio_out(P4, 1)
    END SELECT
  END WITH
END SUB


' *****  main  *****

VAR io = NEW PruIo '*< create a PruIo structure, wakeup devices

WITH *io
  DO '                                    pseudo loop, just to avoid GOTOs
    IF .Errr THEN      ?"initialisation failed (" & *.Errr & ")" : EXIT DO

'                                             initial output pins settings
    IF .gpio_set(P1, PRUIO_OUT1) THEN ?"failed setting P1 (" & *.Errr & ")"
    IF .gpio_set(P2, PRUIO_OUT0) THEN ?"failed setting P2 (" & *.Errr & ")"
    IF .gpio_set(P3, PRUIO_OUT0) THEN ?"failed setting P3 (" & *.Errr & ")"
    IF .gpio_set(P4, PRUIO_OUT1) THEN ?"failed setting P4 (" & *.Errr & ")"
    IF .Errr THEN                                                  EXIT DO

'       pin config OK, transfer local settings to PRU and start PRU driver
    IF .config() THEN          ?"config failed (" & *.Errr & ")" : EXIT DO

    ? '                                            print user informations
    ?"Controls: (other keys quit, 1 and 3 only when Direction = 0)"
    ?"                       8 = faster"
    ?"  4 = rotate CW        5 = stop, hold position   6 = rotate CCW"
    ?"  1 = single step CW   2 = slower                3 = single step CCW"
    ?"  0 = stop, power off"
    ?
    ?"Direction","Sleep" : ?

    VAR w = 128, d = 0, x = 1, y = CSRLIN() - 1
    LOCATE y, x, 0 : ?RIGHT(" " & d, 2), RIGHT("  " & w, 3); '   user info
    DO '                                                      endless loop
      VAR k = ASC(INKEY())
      IF k THEN
        SELECT CASE AS CONST k '                  react on user keystrokes
        CASE ASC("2") : IF w < 512 THEN w SHL= 1
        CASE ASC("8") : IF w >   1 THEN w SHR= 1
        CASE ASC("4") : d =  1
        CASE ASC("7") : d =  2
        CASE ASC("9") : d = -2
        CASE ASC("6") : d = -1
        CASE ASC("0") : d =  0 : .gpio_out(P1, 0) : .gpio_out(P2, 0) : .gpio_out(P3, 0) : .gpio_out(P4, 0)
        CASE ASC("5") : d =  0 : move(io, d)
        CASE ASC("1") : IF 0 = d THEN move(io,  1)
        CASE ASC("3") : IF 0 = d THEN move(io, -1)
        CASE ELSE : EXIT DO
        END SELECT

        LOCATE y, x, 0 : ?RIGHT(" " & d, 2), RIGHT("  " & w, 3); 'user info
      END IF
      IF d THEN move(io, d) '                               move the motor
      SLEEP w '                              control the frequency = speed
    LOOP
    ?
    ' switch off pins
    .gpio_out(P1, 0) : .gpio_out(P2, 0) : .gpio_out(P3, 0) : .gpio_out(P4, 0)
    ' reset pin configurations
    .gpio_set(P1, PRUIO_PIN_RESET)
    .gpio_set(P2, PRUIO_PIN_RESET)
    .gpio_set(P3, PRUIO_PIN_RESET)
    .gpio_set(P4, PRUIO_PIN_RESET)
  LOOP UNTIL 1
END WITH

DELETE io '                      reset ADC, PinMux and GPIOs, clear memory
