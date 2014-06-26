/'* \file oszi.bas
\brief Example: draw a graph of analog inputs.

This file contains an example on how to use libpruio to continuously
draw a graph of the sampled data from the analog input lines.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all oszi.bas

'/

'* include libpruio
#INCLUDE ONCE "../pruio/pruio.bi"
'* include FreeBASIC grafics
#INCLUDE ONCE "fbgfx.bi"

VAR S_W = 0, S_H = 0, gap = 2, BPP = 0, full = fb.GFX_FULLSCREEN
SCREENINFO S_W, S_H, BPP '                         get screen resolution
IF LEN(COMMAND) THEN '                   customized resolution required?
  VAR p = INSTR(COMMAND, "x") _
    , w = VALINT(COMMAND) _
    , h = VALINT(MID(COMMAND, p + 1))
  IF p ANDALSO w ANDALSO h THEN
    IF w < S_W - 4 ANDALSO h < S_H - 24 THEN full = fb.GFX_WINDOWED
    S_W = IIF(w < S_W, w, S_W) '           set maximum custom resolution
    S_H = IIF(h < S_H, h, S_H)
  ELSE
    PRINT "set resolution like 640x400"
    END
  END IF
END IF

SCREENRES S_W, S_H, BPP, , full '                  set screen resolution
IF 0 = SCREENPTR THEN                  PRINT "no grafic available" : END

DIM AS uint32 _
  last(...) = { _  '*< the previous data of the channels
    0 _
  , 0 _
  , 0 _
  , 0 _
  , 0 _
  , 0 _
  , 0 _
  , 0 _
    }, _
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
    IF .Errr THEN               ?"New failed (" & *.Errr & ")" : EXIT DO

    IF .config() THEN        ?"config failed (" & *.Errr & ")" : EXIT DO

    S_H -= 1
    VAR scale = S_H / 65520
    FOR i AS INTEGER = 0 TO 7
      last(i) = S_H - CUINT(.Value[i + 1] * scale)
    NEXT

    DO
      VAR k = ASC(INKEY())
      IF k THEN '                                      handle user input
        VAR m = .StepMask
        SELECT CASE AS CONST k
        CASE ASC("0") : m XOR= 1 SHL 1
        CASE ASC("1") : m XOR= 1 SHL 2
        CASE ASC("2") : m XOR= 1 SHL 3
        CASE ASC("3") : m XOR= 1 SHL 4
        CASE ASC("4") : m XOR= 1 SHL 5
        CASE ASC("5") : m XOR= 1 SHL 6
        CASE ASC("6") : m XOR= 1 SHL 7
        CASE ASC("7") : m XOR= 1 SHL 8
        CASE ASC("+") : m = &b111111110
        CASE ELSE : EXIT DO
        END SELECT
        IF m THEN
          .StepMask = m
          WHILE .DRam[1] <> PRUIO_MSG_INIT_OK : WEND
          .DRam[1] = .StepMask
        END IF
      END IF

      FOR x AS INTEGER = 0 TO S_W - gap STEP gap '            draw graph
        LINE (x + 1, 0) - STEP (gap, S_H), 0, BF
        FOR i AS INTEGER = 1 TO 8
          IF 0 = BIT(.StepMask, i) THEN CONTINUE FOR
          VAR neu = S_H - CUINT(.Value[i] * scale) _
              , j = i - 1
          LINE (x, last(j)) - (x + gap, neu), col(j)
          last(j) = neu
        NEXT
        LINE (0, 0) - STEP (gap, S_H), 0, BF
      NEXT
    LOOP
  LOOP UNTIL 1
  IF .Errr THEN ?"press any key to quit" : SLEEP
END WITH

DELETE io


