/*! \file 1.c
\brief Example: minimal code for ADC input.

This file contains an short and simple example for text output of the
analog input lines. It's designed for the description pages and shows
the basic usage of libpruio with a minimum of source code, translatable
between FreeBASIC and C.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

gcc -Wall -o 1 1.c /usr/local/lib/freebasic/fbrt0.o -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++

*/


#include "stdio.h"
#include "../c_wrapper/pruio_c_wrapper.h" // include header

int main(int argc, char **argv)
{
  int i, n;
  PruIo *io = pruio_new(0, 0x98, 0 ,1);   // create new driver UDT
  pruio_config(io, 0, 0x1FE, 0, 4, 0);    // upload (default) settings, start IO mode

/* now current ADC samples are available for AIN0 to AIN7 in array Value[] */

  for(n = 1; n <= 13; n++) {                           /* print some lines */
    for(i = 1; i < 9; i++)                                    /* all steps */
      printf(" %4X", io->Value[i]);   /* output one channel as hexadecimal */
    printf("\n");                                             /* next line */
  }

/* we're done */

  pruio_destroy(io);                      // destroy driver structure
	return 0;
} // end of main
