/*! \file sos.c
\brief Example: blink user LED 3.

This file contains an example on how to use libpruio to control the
user LED 3 (near ethernet connector) on the beaglebone board.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

gcc -Wall -o sos sos.c /usr/local/lib/freebasic/fbrt0.o -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++

*/

#define _GNU_SOURCE 1
#include "stdio.h"
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include "../c_wrapper/pruio_c_wrapper.h"  /* include header */


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

  /* select returns 0 if timeout, 1 if input available, -1 if error. */
  return TEMP_FAILURE_RETRY(select(FD_SETSIZE,
                                   &set, NULL, NULL,
                                   &timeout));
}

#define PIN 24
#define OUT_K pruio_gpio_out(io, PIN, 1) ; isleep(250) ; pruio_gpio_out(io, PIN, 0) ; isleep(150) ;
#define OUT_L pruio_gpio_out(io, PIN, 1) ; isleep(750) ; pruio_gpio_out(io, PIN, 0) ; isleep(150) ;
#define OUT_S OUT_K ; OUT_K ; OUT_K ; isleep(250)
#define OUT_O OUT_L ; OUT_L ; OUT_L ; isleep(250)

int main(int argc, char **argv)
{
  PruIo *io = pruio_new(0, 0x98, 0, 1); /* create new driver UDT */
  do {
    if (io->Errr) {
               printf("initialisation failed (%s)\n", io->Errr); break;}

    if (pruio_gpio_set(io, PIN, PRUIO_OUT0, PRUIO_UNLOCK_NEW)) {
            printf("pin configuration failed (%s)\n", io->Errr); break;}

    if (pruio_config(io, 0, 0x1FE, 0, 4, 0)) {
                       printf("config failed (%s)\n", io->Errr); break;}

    printf("watch SOS code on user LED 3 (near ethernet connector)\n\n");
    printf("execute the following command to get rid of mmc1 triggers\n");
    printf("  sudo su && echo none > /sys/class/leds/beaglebone:green:usr3/trigger && exit\n\n");
    printf("press any key to quit");

    struct termios oldt, newt;            /* make terminal non-blocking */
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 1;
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    while(0 >= getchar()) {                 /* run loop until keystroke */
      OUT_S;
      OUT_O;
      OUT_S;
      isleep(1500);
    }

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );          /* reset terminal */

    pruio_gpio_out(io, PIN, 0);
    if (pruio_gpio_set(io, PIN, PRUIO_PIN_RESET, PRUIO_LOCK_ORIG))
                 printf("pin re-configuration failed (%s)\n", io->Errr);
  } while (0);
  printf("\n");

  pruio_destroy(io);       /* destroy driver structure */
	return 0;
}
