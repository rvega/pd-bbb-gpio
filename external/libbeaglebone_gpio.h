#ifndef __BBB_IO_COMMON
#define ___BBB_IO_COMMON

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

#define MAX_DIGITAL_PINS 200
#define MAX_ANALOG_PINS 14 // Analog iputs 7 to 14 are handled by mux

unsigned int input_string_to_pin_number(char* str);
char* input_pin_number_to_string(unsigned int pin);


#endif
