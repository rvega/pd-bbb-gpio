#include "m_pd.h"

/* #include <string.h> */
#include <pthread.h>
#include <unistd.h>
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
#else
#define debug(s,t)   
#endif


////////////////////////////////////////////////////////////////////////////////
// Constants
//

#define MAX_PINS 100

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

   int initialized_digital_pin_count;
   float initialized_digital_pins[MAX_PINS];

   int initialized_analog_pin_count;
   float initialized_analog_pins[MAX_PINS];
   float analog_values[MAX_PINS];
} t_input;

// A pointer to the class object.
t_class *input_class;

////////////////////////////////////////////////////////////////////////////////
// Poll for pin changes
// 

static void* input_poll_loop(void* user_param){
   t_input* x = (t_input*)user_param;
   int i;

   while(1){
      for(i=0; i < x->initialized_analog_pin_count; i++){
         int pin = x->initialized_analog_pins[i];
         t_atom output[2];
         SETFLOAT(output, pin);
         SETFLOAT(output+1, x->io->Value[pin]);

         sys_lock();
         outlet_list(x->outlet_right, 0, 2, output);
         sys_unlock();
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
   x->io = pruio_new(0, 0x98, 0, 1);
   if (x->io->Errr) {
      printf("Initialisation failed (%s)\n", x->io->Errr);
   }

   if(pruio_config(x->io, 0, 0x1FE, 0, 4, 0)){
      printf("Config failed (%s)\n", x->io->Errr); 
   }
}

////////////////////////////////////////////////////////////////////////////////
// Init digital pins
// 

////////////////////////////////////////////////////////////////////////////////
// Init Analog Pins
// 
static void input_init_analog_pin(t_input* x, float pin_num){
   debug("Inited analog pin %f", pin_num);
   x->initialized_analog_pins[x->initialized_analog_pin_count] = pin_num;
   x->initialized_analog_pin_count ++;
}

static void input_uninit_all_analog_pins(t_input* x){
   int i;
   for(i=0; i<x->initialized_analog_pin_count; i++){
      debug("Uninited analog pin %f", x->initialized_analog_pins[i]);
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
      // TODO: Check BB's datasheet to see which pins are good to use
      pin_num = atom_getfloatarg(i, argc, argv);
      if(pin_num==0){
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
/*static void input_digital(t_input* x, t_symbol* s, int argc, t_atom* argv) {
UNUSED_PARAMETER(x);
UNUSED_PARAMETER(s);
UNUSED_PARAMETER(argc);
UNUSED_PARAMETER(argv);
}*/

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

   input_init_gpio(x);

   return (void *)x;
}

static void input_free(t_input *x) { 
   /* input_uninit_all_digital_pins(x); */
   debug("Freeing",0);
   input_uninit_all_analog_pins(x);
   input_stop_thread(x);
   pruio_destroy(x->io);
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

void input_setup(void) {
   input_class = class_new(gensym("input"), (t_newmethod)input_new, (t_method)input_free, sizeof(t_input), CLASS_DEFAULT, (t_atomtype)0);
   /* class_addmethod(input_class, (t_method)input_digital, gensym("digital"), A_GIMME, 0); */
   class_addmethod(input_class, (t_method)input_analog, gensym("analog"), A_GIMME, 0);
}
