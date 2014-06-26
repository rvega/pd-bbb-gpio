/'* \file sos.bas
\brief Example: blink user LED 3.

This file contains an example on how to use libpruio to control the
user LED 3 (near ethernet connector) on the beaglebone board.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all sos.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"

#DEFINE PIN 24 '' CPU ball # of user led 3
#DEFINE OUT_K .gpio_out(PIN, 1) : SLEEP 250 : .gpio_out(PIN, 0) : SLEEP 150
#DEFINE OUT_L .gpio_out(PIN, 1) : SLEEP 750 : .gpio_out(PIN, 0) : SLEEP 150
#DEFINE OUT_S OUT_K : OUT_K : OUT_K : SLEEP 250
#DEFINE OUT_O OUT_L : OUT_L : OUT_L : SLEEP 250

' *****  main  *****

VAR io = NEW PruIo '*< create a PruIo structure, wakeup devices
WITH *io
  DO
    IF .Errr THEN    ?"initialisation failed (" & *.Errr & ")" : EXIT DO
    IF .gpio_set(PIN, PRUIO_OUT0, PRUIO_UNLOCK_NEW) THEN _
                  ?"pin configuration failed (" & *.Errr & ")" : EXIT DO
    IF .config() THEN _
                             ?"config failed (" & *.Errr & ")" : EXIT DO
    ?"watch SOS code on user LED 3 (near ethernet connector)"
    ?
    ?"execute the following command to get rid of mmc1 triggers"
    ?"  sudo su && echo none > /sys/class/leds/beaglebone:green:usr3/trigger && exit"
    ?
    ?"press any key to quit"
    DO '                           print current state (until keystroke)
      OUT_S
      OUT_O
      OUT_S
      SLEEP 1500
    LOOP UNTIL LEN(INKEY())
  LOOP UNTIL 1
  .gpio_out(PIN, 0) '                                       shut off LED
  IF .gpio_set(PIN, , PRUIO_LOCK_ORIG) THEN _ '    re-configure CPU ball
                         ?"pin re-configuration failed (" & *.Errr & ")"

  IF .Errr THEN ?"press any key to quit" : SLEEP
END WITH

DELETE io '                    reset ADC, PinMux and GPIOs, clear memory
