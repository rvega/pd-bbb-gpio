/*! \file stepper.c
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

gcc -Wall -o stepper stepper.c /usr/local/lib/freebasic/fbrt0.o -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++ -Wno-unused-variable

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

// output pins for the motor driver
#define P1 P8_08
#define P2 P8_10
#define P3 P8_12
#define P4 P8_14


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

/*! \brief make the motor move the next step.
\param Io pointer to PruIo structure
\param Rot direction of rotation (1 or -1)

This function sets 4 output pins for a stepper motor driver. It
remembers the last step as static variable (starting at 0 = zero) and
adds the new position to it. So the Rot parameter should either be 1 or
-1 to make the motor move one step in any direction.

*/
void
move(PruIo *Io, char Rot) {
  static int p = 0;

  p += Rot;
  p &= 7; // &b111

  switch (p){
    case 1:
      pruio_gpio_out(Io, P1, 1); pruio_gpio_out(Io, P2, 0); pruio_gpio_out(Io, P3, 0); pruio_gpio_out(Io, P4, 0); break;
    case 2:
      pruio_gpio_out(Io, P1, 1); pruio_gpio_out(Io, P2, 1); pruio_gpio_out(Io, P3, 0); pruio_gpio_out(Io, P4, 0); break;
    case 3:
      pruio_gpio_out(Io, P1, 0); pruio_gpio_out(Io, P2, 1); pruio_gpio_out(Io, P3, 0); pruio_gpio_out(Io, P4, 0); break;
    case 4:
      pruio_gpio_out(Io, P1, 0); pruio_gpio_out(Io, P2, 1); pruio_gpio_out(Io, P3, 1); pruio_gpio_out(Io, P4, 0); break;
    case 5:
      pruio_gpio_out(Io, P1, 0); pruio_gpio_out(Io, P2, 0); pruio_gpio_out(Io, P3, 1); pruio_gpio_out(Io, P4, 0); break;
    case 6:
      pruio_gpio_out(Io, P1, 0); pruio_gpio_out(Io, P2, 0); pruio_gpio_out(Io, P3, 1); pruio_gpio_out(Io, P4, 1); break;
    case 7:
      pruio_gpio_out(Io, P1, 0); pruio_gpio_out(Io, P2, 0); pruio_gpio_out(Io, P3, 0); pruio_gpio_out(Io, P4, 1); break;
    default:
      pruio_gpio_out(Io, P1, 1); pruio_gpio_out(Io, P2, 0); pruio_gpio_out(Io, P3, 0); pruio_gpio_out(Io, P4, 1);
  }
}


int main(int argc, char **argv)
{
  PruIo *io = pruio_new(0, 0x98, 0, 1); /* create new driver structure */
  do {
    if (io->Errr) {
               printf("initialisation failed (%s)\n", io->Errr); break;}

    if (pruio_gpio_set(io, P1, PRUIO_OUT1, PRUIO_LOCK_CHECK)) {
                   printf("failed setting P1 (%s)\n", io->Errr); break;}
    if (pruio_gpio_set(io, P2, PRUIO_OUT0, PRUIO_LOCK_CHECK)) {
                   printf("failed setting P2 (%s)\n", io->Errr); break;}
    if (pruio_gpio_set(io, P3, PRUIO_OUT0, PRUIO_LOCK_CHECK)) {
                   printf("failed setting P3 (%s)\n", io->Errr); break;}
    if (pruio_gpio_set(io, P4, PRUIO_OUT1, PRUIO_LOCK_CHECK)) {
                   printf("failed setting P4 (%s)\n", io->Errr); break;}

    //' pin config OK, transfer local settings to PRU and start PRU driver
    if (pruio_config(io, 0, 0x1FE, 0, 4, 0)) {
                       printf("config failed (%s)\n", io->Errr); break;}

    //'                                            print user informations
    printf("Controls: (other keys quit, 1 and 3 only when Direction = 0)\n");
    printf("                       8 = faster\n");
    printf("  4 = rotate CW        5 = stop, hold position   6 = rotate CCW\n");
    printf("  1 = single step CW   2 = slower                3 = single step CCW\n");
    printf("  0 = stop, power off\n\n");
    printf("Direction\tSleep\n");

    struct termios oldt, newt; //               make terminal non-blocking
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON );
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 1;
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    int w = 128, d = 0;
    printf("%2d\t\t%3d", d, w); //                         user information
    fflush(STDIN_FILENO);
    while(1) { //                                         run endless loop
      if (d) move(io, d); //                                 move the motor
      if (1 == isleep(w)) {
        switch (getchar()) { //                         evaluate keystroke
          case '2': if (w < 512) w <<= 1; break;
          case '8': if (w >   1) w >>= 1; break;
          case '4': d =  1; break;
          case '7': d =  2; break;
          case '9': d = -2; break;
          case '6': d = -1; break;
          case '0': d =  0; pruio_gpio_out(io, P1, 0); pruio_gpio_out(io, P2, 0); pruio_gpio_out(io, P3, 0); pruio_gpio_out(io, P4, 0); break;
          case '5': d =  0; move(io, d); break;
          case '1': if (d == 0) move(io,  1); break;
          case '3': if (d == 0) move(io, -1); break;
          default: goto finish;
        };
        printf("\r%2d\t\t%3d", d, w); //                   user information
        fflush(STDIN_FILENO);
      }
    }

finish:
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt ); //            reset terminal

    // switch off pins
    pruio_gpio_out(io, P1, 0); pruio_gpio_out(io, P2, 0); pruio_gpio_out(io, P3, 0); pruio_gpio_out(io, P4, 0);
    // reset pin configurations
    pruio_gpio_set(io, P1, PRUIO_PIN_RESET, PRUIO_LOCK_CHECK);
    pruio_gpio_set(io, P2, PRUIO_PIN_RESET, PRUIO_LOCK_CHECK);
    pruio_gpio_set(io, P3, PRUIO_PIN_RESET, PRUIO_LOCK_CHECK);
    pruio_gpio_set(io, P4, PRUIO_PIN_RESET, PRUIO_LOCK_CHECK);

    printf("\n");
  } while (0);

  pruio_destroy(io);       /* destroy driver structure */
	return 0;
}
