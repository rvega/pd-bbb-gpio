#ifndef __BBB_IO_COMMON
#define __BBB_IO_COMMON

#include "pruio_c_wrapper.h"
#include "pruio_pins.h"

////////////////////////////////////////////////////////////////////////////////
// Debug
//

#define DBG

#ifdef DBG
#include <stdio.h>
#define debug(s,t) post(s,t)
#define debug2(s,t,u) post(s,t,u)
#else
#define debug(s,t)   
#define debug2(s,t)   
#endif


////////////////////////////////////////////////////////////////////////////////
// Constants
//


#ifndef LIBRARY_NAME
#define LIBRARY_NAME "beaglebone_gpio"
#endif

#define UNUSED_PARAMETER(X) ((void)(X))

// Optional
// #define USE_ANALOG_MULTIPLEXER

#ifdef USE_ANALOG_MULTIPLEXER
#define MAX_ANALOG_PINS 14 // Analog iputs 7 to 14 are handled by mux
#else
#define MAX_ANALOG_PINS 7
#endif

#define MAX_DIGITAL_PINS 200

////////////////////////////////////////////////////////////////////////////////
// Functions
//

unsigned int bbb_string_to_pin_number(char* str);
char* bbb_pin_number_to_string(unsigned int pin);


#endif
