/*! \file analyse.c
\brief Example: analyse the devices configurations.

This file contains an example on how to use libpruio to read the
original configuration of the devices. It creates a PruIo structure
containing the initial data and then prints out in a human-readable
form.

Licence: GPLv3

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


Compile by:

gcc -Wall -o analyse analyse.c /usr/local/lib/freebasic/fbrt0.o -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++ -Wno-unused-variable

*/

#include "stdio.h"
#include "../c_wrapper/pruio_c_wrapper.h"
#include "../c_wrapper/pruio_pins.h"


int main(int argc, char **argv)
{
  PruIo *io = pruio_new(0, 0x98, 0, 1); /* create new driver UDT */
  do {
    if (io->Errr) {
               printf("initialisation failed (%s)\n", io->Errr); break;}

    int i;
    for(i = 0; i <= PRUIO_GPIO_AZ; i++) {
      int x = i * (PRUIO_GPIO_DATA >> 2);
      if (io->GpioOrg[x + 4] == 2) {
        printf("GPIO%d was on\n", i);
        printf("    OE: %12o\n", io->GpioOrg[x + 1]);
        printf("  INT0: %12o\n", io->GpioOrg[x + 2]);
        printf("  INT1: %12o\n", io->GpioOrg[x + 3]);
      } else {
        printf("GPIO%d was off, COUNT: %d\n", i, io->GpioOrg[x + 5]);
      }
    }

    printf("Unlocked Pins:\n");
    for (i = 0; i <= PRUIO_BALL_AZ; i++) {
      if (io->BallRef[i] != 255) printf("  %s\n", pruio_gpio_get_config(io, i));
    }

    printf("Locked header Pins:\n");
    for (i = 0; i <= sizeof(P8_Pins) / sizeof(uint8); i++) {
      uint8 b = P8_Pins[i];
      if (io->BallRef[b] == 255) printf("  %s\n", pruio_gpio_get_config(io, b));
    }
    for (i = 0; i <= sizeof(P9_Pins) / sizeof(uint8); i++) {
      uint8 b = P9_Pins[i];
      if (io->BallRef[b] == 255) printf("  %s\n", pruio_gpio_get_config(io, b));
    }

    if (io->AdcOrg[0]) {
      printf("ADC was on\n");
      printf("        REVISION: %8X\n" , io->AdcOrg[ 0]);
      printf("       SYSCONFIG: %12o\n", io->AdcOrg[ 4]);
      printf("  IRQ_STATUS_RAW: %12o\n", io->AdcOrg[ 9]);
      printf("      IRQ_STATUS: %12o\n", io->AdcOrg[10]);
      printf("   IRQENABLE_SET: %12o\n", io->AdcOrg[11]);
      printf("   IRQENABLE_CLR: %12o\n", io->AdcOrg[12]);
      printf("       IRQWAKEUP: %12o\n", io->AdcOrg[13]);
      printf("   DMAENABLE_SET: %12o\n", io->AdcOrg[14]);
      printf("   DMAENABLE_CLR: %12o\n", io->AdcOrg[15]);
      printf("            CRTL: %12o\n", io->AdcOrg[16]);
      printf("         ADCSTAT: %12o\n", io->AdcOrg[17]);
      printf("        ADCRANGE: %8X\n" , io->AdcOrg[18]);
      printf("      ADC_CLKDIV: %8X\n" , io->AdcOrg[19]);
      printf("        ADC_MISC: %12o\n", io->AdcOrg[20]);
      printf("  Steps:            config  ,   delay\n");
      printf("       idle step: 0x%8X\n", io->AdcOrg[22]);
      printf("     charge step: 0x%8X, 0x%8X\n", io->AdcOrg[23], io->AdcOrg[24]);
      for (i = 1; i <= 16; i++) {
        int x= 23 + 2 * i;
        printf("          step%2d: 0x%8X, 0x%8X\n", i, io->AdcOrg[x], io->AdcOrg[x + 1]);
      }
    }
    else {
      printf("ADC was off\n");
      printf("      REVISION: %8X\n", io->AdcOrg[1]);
      printf("  wakeup-count: %8X\n", io->AdcOrg[2]);
    }

  } while (0);

  pruio_destroy(io);       /* destroy driver structure */
	return 0;
}
