/'* \file 1.bas
\brief Example: minimal code for ADC input.

This file contains an short and simple example for text output of the
analog input lines. It's designed for the description pages and shows
the basic usage of libpruio with a minimum of source code, translatable
between FreeBASIC and C.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

fbc -w all 1.bas

'/


#INCLUDE ONCE "../pruio/pruio.bi" '   include header
VAR io = NEW PruIo()              '*< create new driver UDT
io->config()                      '   upload (default) settings, start IO mode

''     now current ADC samples are available for AIN0 to AIN7 in array Value[]

FOR n AS INTEGER = 1 TO 13 ''                                 print some lines
  FOR i AS INTEGER = 1 TO 8 ''                                       all steps
    PRINT " " & HEX(io->Value[i], 4); ''     output one channel as hexadecimal
  NEXT
  PRINT ''                                                           next line
NEXT

'' we're done

DELETE io                         '   destroy driver UDT
