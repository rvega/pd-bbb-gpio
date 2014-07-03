////////////////////////////////////////////////////////////////////////////////
// TO-DO
// * This object should be a singleton.
// * Set analog input precision from outside message. 
//   Currently hard coded to 8 bits


////////////////////////////////////////////////////////////////////////////////

#include "m_pd.h"

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "pruio_c_wrapper.h"
#include "pruio_pins.h"

#ifndef LIBRARY_NAME
#define LIBRARY_NAME "beaglebone_gpio"
#endif

#define UNUSED_PARAMETER(X) ((void)(X))

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

#define MAX_DIGITAL_PINS 67
#define MAX_ANALOG_PINS 7
#define DEBOUNCING_PERIOD 1

static unsigned int input_string_to_pin_number(char* str){
   if(!strcmp(str, "P8_03")) return P8_03;
   else if(!strcmp(str, "P8_04")) return P8_04;
   else if(!strcmp(str, "P8_05")) return P8_05;
   else if(!strcmp(str, "P8_06")) return P8_06;
   else if(!strcmp(str, "P8_07")) return P8_07;
   else if(!strcmp(str, "P8_08")) return P8_08;
   else if(!strcmp(str, "P8_09")) return P8_09;
   else if(!strcmp(str, "P8_10")) return P8_10;
   else if(!strcmp(str, "P8_11")) return P8_11;
   else if(!strcmp(str, "P8_12")) return P8_12;
   else if(!strcmp(str, "P8_13")) return P8_13;
   else if(!strcmp(str, "P8_14")) return P8_14;
   else if(!strcmp(str, "P8_15")) return P8_15;
   else if(!strcmp(str, "P8_16")) return P8_16;
   else if(!strcmp(str, "P8_17")) return P8_17;
   else if(!strcmp(str, "P8_18")) return P8_18;
   else if(!strcmp(str, "P8_19")) return P8_19;
   else if(!strcmp(str, "P8_20")) return P8_20;
   else if(!strcmp(str, "P8_21")) return P8_21;
   else if(!strcmp(str, "P8_22")) return P8_22;
   else if(!strcmp(str, "P8_23")) return P8_23;
   else if(!strcmp(str, "P8_24")) return P8_24;
   else if(!strcmp(str, "P8_25")) return P8_25;
   else if(!strcmp(str, "P8_26")) return P8_26;
   else if(!strcmp(str, "P8_27")) return P8_27;
   else if(!strcmp(str, "P8_28")) return P8_28;
   else if(!strcmp(str, "P8_29")) return P8_29;
   else if(!strcmp(str, "P8_30")) return P8_30;
   else if(!strcmp(str, "P8_31")) return P8_31;
   else if(!strcmp(str, "P8_32")) return P8_32;
   else if(!strcmp(str, "P8_33")) return P8_33;
   else if(!strcmp(str, "P8_34")) return P8_34;
   else if(!strcmp(str, "P8_35")) return P8_35;
   else if(!strcmp(str, "P8_36")) return P8_36;
   else if(!strcmp(str, "P8_37")) return P8_37;
   else if(!strcmp(str, "P8_38")) return P8_38;
   else if(!strcmp(str, "P8_39")) return P8_39;
   else if(!strcmp(str, "P8_40")) return P8_40;
   else if(!strcmp(str, "P8_41")) return P8_41;
   else if(!strcmp(str, "P8_42")) return P8_42;
   else if(!strcmp(str, "P8_43")) return P8_43;
   else if(!strcmp(str, "P8_44")) return P8_44;
   else if(!strcmp(str, "P8_45")) return P8_45;
   else if(!strcmp(str, "P8_46")) return P8_46;
   else if(!strcmp(str, "P9_11")) return P9_11;
   else if(!strcmp(str, "P9_12")) return P9_12;
   else if(!strcmp(str, "P9_13")) return P9_13;
   else if(!strcmp(str, "P9_14")) return P9_14;
   else if(!strcmp(str, "P9_15")) return P9_15;
   else if(!strcmp(str, "P9_16")) return P9_16;
   else if(!strcmp(str, "P9_17")) return P9_17;
   else if(!strcmp(str, "P9_18")) return P9_18;
   else if(!strcmp(str, "P9_19")) return P9_19;
   else if(!strcmp(str, "P9_20")) return P9_20;
   else if(!strcmp(str, "P9_21")) return P9_21;
   else if(!strcmp(str, "P9_22")) return P9_22;
   else if(!strcmp(str, "P9_23")) return P9_23;
   else if(!strcmp(str, "P9_24")) return P9_24;
   else if(!strcmp(str, "P9_25")) return P9_25;
   else if(!strcmp(str, "P9_26")) return P9_26;
   else if(!strcmp(str, "P9_27")) return P9_27;
   else if(!strcmp(str, "P9_28")) return P9_28;
   else if(!strcmp(str, "P9_29")) return P9_29;
   else if(!strcmp(str, "P9_30")) return P9_30;
   else if(!strcmp(str, "P9_31")) return P9_31;
   else if(!strcmp(str, "P9_41")) return P9_41;
   else if(!strcmp(str, "P9_42")) return P9_42;
   else return 9999; // Not valid.
}

static char* input_pin_number_to_string(unsigned int pin){
   if(pin == P8_03) return "P8_03";
   else if(pin == P8_04) return "P8_04";
   else if(pin == P8_05) return "P8_05";
   else if(pin == P8_06) return "P8_06";
   else if(pin == P8_07) return "P8_07";
   else if(pin == P8_08) return "P8_08";
   else if(pin == P8_09) return "P8_09";
   else if(pin == P8_10) return "P8_10";
   else if(pin == P8_11) return "P8_11";
   else if(pin == P8_12) return "P8_12";
   else if(pin == P8_13) return "P8_13";
   else if(pin == P8_14) return "P8_14";
   else if(pin == P8_15) return "P8_15";
   else if(pin == P8_16) return "P8_16";
   else if(pin == P8_17) return "P8_17";
   else if(pin == P8_18) return "P8_18";
   else if(pin == P8_19) return "P8_19";
   else if(pin == P8_20) return "P8_20";
   else if(pin == P8_21) return "P8_21";
   else if(pin == P8_22) return "P8_22";
   else if(pin == P8_23) return "P8_23";
   else if(pin == P8_24) return "P8_24";
   else if(pin == P8_25) return "P8_25";
   else if(pin == P8_26) return "P8_26";
   else if(pin == P8_27) return "P8_27";
   else if(pin == P8_28) return "P8_28";
   else if(pin == P8_29) return "P8_29";
   else if(pin == P8_30) return "P8_30";
   else if(pin == P8_31) return "P8_31";
   else if(pin == P8_32) return "P8_32";
   else if(pin == P8_33) return "P8_33";
   else if(pin == P8_34) return "P8_34";
   else if(pin == P8_35) return "P8_35";
   else if(pin == P8_36) return "P8_36";
   else if(pin == P8_37) return "P8_37";
   else if(pin == P8_38) return "P8_38";
   else if(pin == P8_39) return "P8_39";
   else if(pin == P8_40) return "P8_40";
   else if(pin == P8_41) return "P8_41";
   else if(pin == P8_42) return "P8_42";
   else if(pin == P8_43) return "P8_43";
   else if(pin == P8_44) return "P8_44";
   else if(pin == P8_45) return "P8_45";
   else if(pin == P8_46) return "P8_46";
   else if(pin == P9_11) return "P9_11";
   else if(pin == P9_12) return "P9_12";
   else if(pin == P9_13) return "P9_13";
   else if(pin == P9_14) return "P9_14";
   else if(pin == P9_15) return "P9_15";
   else if(pin == P9_16) return "P9_16";
   else if(pin == P9_17) return "P9_17";
   else if(pin == P9_18) return "P9_18";
   else if(pin == P9_19) return "P9_19";
   else if(pin == P9_20) return "P9_20";
   else if(pin == P9_21) return "P9_21";
   else if(pin == P9_22) return "P9_22";
   else if(pin == P9_23) return "P9_23";
   else if(pin == P9_24) return "P9_24";
   else if(pin == P9_25) return "P9_25";
   else if(pin == P9_26) return "P9_26";
   else if(pin == P9_27) return "P9_27";
   else if(pin == P9_28) return "P9_28";
   else if(pin == P9_29) return "P9_29";
   else if(pin == P9_30) return "P9_30";
   else if(pin == P9_31) return "P9_31";
   else if(pin == P9_41) return "P9_41";
   else if(pin == P9_42) return "P9_42";
   else return ""; // Not valid.
}

////////////////////////////////////////////////////////////////////////////////
// Data
//

typedef struct input {
   t_object x_obj;
   t_outlet *outlet_left;
   t_outlet *outlet_right;

   pthread_t thread;
   int thread_is_running;

   PruIo* io;

   unsigned int initialized_digital_pin_count;
   unsigned int initialized_digital_pins[MAX_DIGITAL_PINS];
   unsigned int debouncing[MAX_DIGITAL_PINS];
   int16_t digital_values[MAX_DIGITAL_PINS];

   unsigned int initialized_analog_pin_count;
   unsigned int initialized_analog_pins[MAX_ANALOG_PINS];
   int16_t analog_values[MAX_ANALOG_PINS];
} t_input;

// A pointer to the class object.
t_class *input_class;

////////////////////////////////////////////////////////////////////////////////
// Poll for pin changes
// 

static void* input_poll_loop(void* user_param){
   t_input* x = (t_input*)user_param;
   unsigned int i, pin;
   int16_t value;
   int digital_value;
   t_atom output[2];
   t_symbol* pin_symbol;

   while(1){
      for(i=0; i < x->initialized_analog_pin_count; i++){
         pin = x->initialized_analog_pins[i];
         value = x->io->Value[pin];
         // Values from ADC are 12 bits, shift right 4 places because
         // we only care for 8 bit precision.
         /* value = value >> 4;  */
         value = value >> 5; 
         if(x->analog_values[pin] != value){
            x->analog_values[pin] = value; 

            SETFLOAT(output, pin);
            SETFLOAT(output+1, value);
            sys_lock();
            outlet_list(x->outlet_right, 0, 2, output);
            sys_unlock();
         }
      }

      for(i=0; i < x->initialized_digital_pin_count; i++){
         pin = x->initialized_digital_pins[i];
         digital_value = pruio_gpio_get(x->io, pin);
         if(digital_value == -1){
            error("%s/input: Could not read state of pin number '%u'.", LIBRARY_NAME, pin);
            continue;
         }

         if(x->digital_values[pin] != digital_value && x->debouncing[pin]==0){
            x->digital_values[pin] = digital_value; 

            pin_symbol = gensym(input_pin_number_to_string(pin));
            SETSYMBOL(output, pin_symbol);
            SETFLOAT(output+1, digital_value);

            sys_lock();
            outlet_list(x->outlet_left, 0, 2, output);
            sys_unlock();

            x->debouncing[pin] = 1;
         }
         else if(x->debouncing[pin]==DEBOUNCING_PERIOD){
            x->debouncing[pin]=0;
         }
         else if(x->debouncing[pin]>0){
            x->debouncing[pin] ++;
         }
      }
   
      usleep(1000);
   }

   return(0);
}

static void input_start_thread(t_input* x){
   pthread_attr_t attr;
   if(pthread_attr_init(&attr)){
      error("%s/input: Cannot start a new thread.", LIBRARY_NAME);
      return;
   }
   if(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)){
      error("%s/input: Cannot start a new thread.", LIBRARY_NAME);
      return;
   }
   if(pthread_create(&x->thread, &attr, &input_poll_loop, x)){
      error("%s/input: Cannot start a new thread.", LIBRARY_NAME);
      return;
   }
   x->thread_is_running= 1;

   debug("Started thread", 0);
}

static void input_stop_thread(t_input* x){
   while(pthread_cancel(x->thread)){
      debug("Stopping thread", 0);
   }
   debug("Stopped thread", 0);
}

static void input_init_gpio(t_input* x){
   // echo PRUSSDRV> /sys/devices/bone_capemgr.9/slots 
   FILE* f;
   f = fopen("/sys/devices/bone_capemgr.9/slots","w");
   if(f==NULL){
      error("%s/input: Initialisation failed (fopen)", LIBRARY_NAME);
      return;
   }
   fprintf(f, "PRUSSDRV");
   fclose(f);
   usleep(100000);

   x->io = pruio_new(0, 0x98, 0, 1);
   if (x->io->Errr) {
      error("%s/input: Initialisation failed (%s)", LIBRARY_NAME, x->io->Errr);
   }

   if(pruio_config(x->io, 0, 0x1FE, 0, 0, 0)){
      error("%s/input: Config failed (%s)", LIBRARY_NAME, x->io->Errr); 
   }
}

////////////////////////////////////////////////////////////////////////////////
// Init digital pins
// 
static void input_init_digital_pin(t_input* x, char* pin_str){
   unsigned int pin_num = input_string_to_pin_number(pin_str);
   if(pin_num == 9999){
      error("%s/input: Digital pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, pin_str);
      return;
   }

   x->initialized_digital_pins[x->initialized_digital_pin_count] = pin_num;
   x->initialized_digital_pin_count ++;
   x->debouncing[pin_num]=0;
   debug2("Inited digital pin %s (%u)", pin_str, pin_num);
}

static void input_uninit_all_digital_pins(t_input* x){
   unsigned int i;
   for(i=0; i<x->initialized_digital_pin_count; i++){
      debug("Uninited digital pin %u", x->initialized_digital_pins[i]);
   }
   x->initialized_digital_pin_count = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Init Analog Pins
// 
static void input_init_analog_pin(t_input* x, unsigned int pin_num){
   x->initialized_analog_pins[x->initialized_analog_pin_count] = pin_num;
   x->initialized_analog_pin_count ++;
   debug("Inited analog pin %u", pin_num);
}

static void input_uninit_all_analog_pins(t_input* x){
   unsigned int i;
   for(i=0; i<x->initialized_analog_pin_count; i++){
      debug("Uninited analog pin %u", x->initialized_analog_pins[i]);
   }
   x->initialized_analog_pin_count = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Received PD Messages
// 

// Received "analog" message, with parameters
static void input_analog(t_input* x, t_symbol* s, int argc, t_atom* argv) {
   UNUSED_PARAMETER(s);

   int i = 0;
   float pin_num;
   char* pin_str;

   input_uninit_all_analog_pins(x);
   
   // Init new pins
   for(i=0; i<argc; i++){
      pin_num = atom_getfloatarg(i, argc, argv);
      if(pin_num<=0 || pin_num>MAX_ANALOG_PINS){
         pin_str = atom_getsymbolarg(i, argc, argv)->s_name;
         error("%s/input: Analog pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, pin_str);
      }
      else{
         input_init_analog_pin(x, pin_num);
      }
   }

   if(!x->thread_is_running){
      input_start_thread(x);
   }

}

// Received "digital" message, with parameters
static void input_digital(t_input* x, t_symbol* s, int argc, t_atom* argv) {
   UNUSED_PARAMETER(s);

   int i = 0;
   char* pin_str;

   input_uninit_all_digital_pins(x);
   
   // Init new pins
   for(i=0; i<argc; i++){
      pin_str = atom_getsymbolarg(i, argc, argv)->s_name;
      input_init_digital_pin(x, pin_str);
   }

   if(!x->thread_is_running){
      input_start_thread(x);
   }
}

///////////////////////////////////////////////////////////////////////////////
// Constructor, destructor
//

static void *input_new(void) {
   t_input *x = (t_input *)pd_new(input_class);

   x->outlet_left = outlet_new(&x->x_obj, &s_anything);
   x->outlet_right = outlet_new(&x->x_obj, &s_anything);

   x->thread_is_running = 0;
   x->initialized_analog_pin_count = 0;
   x->initialized_digital_pin_count = 0;

   int i;
   for(i=0; i<MAX_DIGITAL_PINS; i++){
      x->debouncing[i] = 0;
   }

   input_init_gpio(x);

   return (void *)x;
}

static void input_free(t_input *x) { 
   debug("Freeing",0);
   input_uninit_all_analog_pins(x);
   input_uninit_all_digital_pins(x);
   input_stop_thread(x);
   pruio_destroy(x->io);
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

void input_setup(void) {
   input_class = class_new(gensym("input"), (t_newmethod)input_new, (t_method)input_free, sizeof(t_input), CLASS_DEFAULT, (t_atomtype)0);
   class_addmethod(input_class, (t_method)input_digital, gensym("digital"), A_GIMME, 0);
   class_addmethod(input_class, (t_method)input_analog, gensym("analog"), A_GIMME, 0);
}
