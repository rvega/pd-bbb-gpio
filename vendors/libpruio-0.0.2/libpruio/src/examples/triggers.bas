/'* \file triggers.bas
\brief Example: start measurements in MM mode by triggers.

This file contains an example on how to use libpruio to measure analog
input and draw a graph of the sampled data. Triggering of measurement
can be done by different events.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all triggers.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"
'* include the convenience macros for header pins
#INCLUDE ONCE "../pruio/pruio_pins.bi"
'* include FreeBASIC grafics
#INCLUDE ONCE "fbgfx.bi"

'* define the pin to use for digital trigger
#DEFINE PIN P8_07
'* define the step number to use for analog trigger
#DEFINE STP 11

VAR S_W = 0, S_H = 0, gap = 2, BPP = 0
SCREENINFO S_W, S_H, BPP '                         get screen resolution
IF LEN(COMMAND) THEN '                   customized resolution required?
  VAR p = INSTR(COMMAND, "x") _
    , w = VALINT(COMMAND) _
    , h = VALINT(MID(COMMAND, p + 1))
  IF p ANDALSO w ANDALSO h THEN
    S_W = IIF(w < S_W, w, S_W) '           set maximum custom resolution
    S_H = IIF(h < S_H, h, S_H)
  ELSE
        PRINT "failed setting resolution (specify like 640x400)" : END 1
  END IF
END IF

SCREENRES S_W, S_H, BPP, , fb.GFX_FULLSCREEN '     set screen resolution
IF 0 = SCREENPTR THEN                PRINT "no grafic available" : END 1

DIM AS uint32 _
  col(...) = { _  '*< the colors for the lines (= channels)
    RGBA(255, 255, 255, 255) _
  , RGBA(255,   0,   0, 255) _
  , RGBA(  0, 255,   0, 255) _
  , RGBA(  0,   0, 255, 255) _
  , RGBA(255, 255,   0, 255) _
  , RGBA(255,   0, 255, 255) _
  , RGBA(  0, 255, 255, 255) _
  , RGBA(127, 127, 127, 255) _
    }

VAR io = NEW PruIo()

WITH *io
  DO '                                  pseudo loop, just to avoid GOTOs
    IF .Errr THEN    ?"initialisation failed (" & *.Errr & ")" : EXIT DO


    IF .gpio_set(PIN, PRUIO_IN_1) THEN _ '            configure GPIO pin
                ?"failed setting trigger pin (" & *.Errr & ")" : EXIT DO

    IF .adc_step(STP, 4, 0, 0, 0) THEN _ '       configure fast ADC step
               ?"failed setting trigger step (" & *.Errr & ")" : EXIT DO

'    config OK here, transfer local settings to PRU and start PRU driver
    VAR samp = S_W \ gap _ '                  number of samples to fetch
      , mask = (1 SHL 5) + (1 SHL 8) _ ' steps 5 & 8 active (AIN4, AIN7)
      ,  tmr = 1e6 '                           the sampling rate (1 kHz)
    IF .config(samp, mask, tmr) THEN _
                             ?"config failed (" & *.Errr & ")" : EXIT DO

    VAR trg = 0
    VAR trg1 = .mm_trg_pin(PIN) : IF 0 = trg1 THEN _
                          ?"trg1 spec failed (" & *.Errr & ")" : EXIT DO
    VAR trg2 = .mm_trg_ain(STP, &h8000) : IF 0 = trg2 THEN _
                          ?"trg2 spec failed (" & *.Errr & ")" : EXIT DO
    VAR trg3 = .mm_trg_pre(0, -&h8000, samp SHR 1) : IF 0 = trg3 THEN _
                          ?"trg3 spec failed (" & *.Errr & ")" : EXIT DO

    S_H -= 1
    VAR lnr = IIF(S_H > 72, S_H SHR 3 - 8, 1) _ '            line number
    , scale = S_H / 65520 _ '              scale sample to screen pixels
        , k = 0 '                                 keycode for user input
    DO '                                     loop to handle user actions
      LOCATE lnr, 1, 0
      ? '                                                print user menu
      ?"Choose trigger type"
      ?"  0 = no trigger (start immediately)"
      ?"  1 = GPIO trigger (pin P8_07 low)"
      ?"  2 = analog trigger, AIN4 > 0.9 V"
      ?"  3 = analog pre-trigger, AIN4 < 0.9 V"
      DO : SLEEP 1000, 0 : k = ASC(INKEY()) : LOOP UNTIL k '     get key

      SELECT CASE AS CONST k '                 re-act on user keystrokes
      CASE ASC("0") : trg = 0
      CASE ASC("1") : trg = trg1 : ?"waiting for GPIO trigger (pin P8_07 low) ...";
      CASE ASC("2") : trg = trg2 : ?"waiting for analog trigger (AIN4 > 0.9 V) ...";
      CASE ASC("3") : trg = trg3 : ?"waiting for analog pre-trigger (any AIN < 0.9 V) ..." ;
      CASE ELSE : EXIT DO
      END SELECT

      IF .mm_start(trg) THEN ?"start failed (" & *.Errr & ")" : CONTINUE DO

      CLS
      FOR c AS INTEGER = 0 TO .ChAz - 1
        VAR i = c + .ChAz, x = gap
        LINE (0, S_H - CUINT(.Value[c] * scale)) _
           - (x, S_H - CUINT(.Value[i] * scale)), col(c)
        DO
          i += .ChAz : IF i >= .Samples THEN EXIT DO
          x += gap
          LINE - (x, S_H - CUINT(.Value[i] * scale)), col(c)
        LOOP
      NEXT
    LOOP
  LOOP UNTIL 1
  IF .Errr THEN ?"press any key to quit" : SLEEP
END WITH

DELETE io

