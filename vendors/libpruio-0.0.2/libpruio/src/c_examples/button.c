/*! \file io_input.c
\brief Example: print digital and analog inputs.

This file contains an example on how to use libpruio to print out the
state of the digital GPIOs and the analog input lines.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

gcc -Wall -o button button.c -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++ -Wno-unused-variable

*/


#define _GNU_SOURCE 1
#include "stdio.h"
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include "../c_wrapper/pruio_c_wrapper.h"
#include "../c_wrapper/pruio_pins.h"

#define PIN P8_07

/*! \brief wait for keystroke or timeout
\param mseconds timeout value in milliseconds
\returns 0 if timeout, 1 if input available, -1 if error

Wait for a keystroke or timeout and return which of the events happened.

*/
int
isleep(unsigned int mseconds)
{
  fd_set set;
  struct timeval timeout;

  /* Initialize the file descriptor set. */
  FD_ZERO(&set);
  FD_SET(STDIN_FILENO, &set);

  /* Initialize the timeout data structure. */
  timeout.tv_sec = 0;
  timeout.tv_usec = mseconds * 1000;

  return TEMP_FAILURE_RETRY(select(FD_SETSIZE,
                                   &set, NULL, NULL,
                                   &timeout));
}

int main(int argc, char **argv)
{
  PruIo *io = pruio_new(0, 0x98, 0, 1); /* create new driver structure */
  do {
    if (io->Errr) {
               printf("initialisation failed (%s)\n", io->Errr); break;}

    if (pruio_gpio_set(io, PIN, PRUIO_IN_1, PRUIO_LOCK_CHECK)) {
                  printf("failed setting PIN (%s)\n", io->Errr); break;}

    if (pruio_config(io, 0, 0x1FE, 0, 4, 0)) {
                       printf("config failed (%s)\n", io->Errr); break;}

    struct termios oldt, newt; //            make terminal non-blocking
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while(!isleep(1)) { //                     run loop until keystroke
      printf("\r%1X", pruio_gpio_get(io, PIN));
      fflush(STDIN_FILENO);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); //           reset terminal

    printf("\n");
  } while (0);

  pruio_destroy(io);       /* destroy driver structure */
	return 0;
}
