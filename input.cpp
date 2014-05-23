#include "m_pd.h"
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <glib.h>
#include <fcntl.h>

#define MAX_PINS 100

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
// Data
//

// State variables in a struct 
typedef struct input {

   t_object x_obj;
   t_outlet *outlet_left;
   t_outlet *outlet_right;

   pthread_t digital_thread;
   int digital_thread_running;
   int inited_digital_pins_count;
   float inited_digital_pins[MAX_PINS];
   char digital_input_buffer[3];

   int analog_thread_running;
   int inited_analog_pins_count;
   float inited_analog_pins[MAX_PINS];

} t_input;

// A pointer to the class object.
t_class *input_class;

////////////////////////////////////////////////////////////////////////////////
// Poll for analog pins
// 

////////////////////////////////////////////////////////////////////////////////
// Get system interrupts from digital pins
// 

void* input_digital_loop(void* user_param){
   //t_input* x = (t_input*)user_param;

   GMainLoop* loop = g_main_loop_new( 0, 0 );

   sys_lock();
   sys_unlock();

   g_main_loop_run( loop );

   return(0);
}

void input_start_digital_thread(t_input* x){
   pthread_attr_t attr;
   if(pthread_attr_init(&attr)){
      error("%s/input: Cannot poll digital inputs state.", LIBRARY_NAME);
      return;
   }
   if(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)){
      error("%s/input: Cannot poll digital inputs state.", LIBRARY_NAME);
      return;
   }
   if(pthread_create(&x->digital_thread, &attr, &input_digital_loop, x)){
      error("%s/input: Cannot poll digital inputs state.", LIBRARY_NAME);
      return;
   }
   x->digital_thread_running = 1;

   debug("Started digital thread", 0);
}

void input_stop_digital_thread(t_input* x){
   while(pthread_cancel(x->digital_thread)){
      debug("Closing digital thread", 0);
   }
   debug("Closed digital thread", 0);
}

////////////////////////////////////////////////////////////////////////////////
// Init pins
// 



void input_init_analog_pin(t_input* x, float pin_num){
   // TODO: do the actual initialization


   int err = 0;
   if(err){
      error("%s/input: Could not initialize analog pin number '%f'.", LIBRARY_NAME, pin_num);
   }
   else{
      debug("Inited analog pin %f", pin_num);
      x->inited_analog_pins[x->inited_analog_pins_count] = pin_num;
      x->inited_analog_pins_count ++;
   }
}

void input_uninit_all_analog_pins(t_input* x){
   int i=0;
   for(i=0; i<x->inited_analog_pins_count; i++){
      // TODO: do the actual uninitialization
      debug("Uninited analog pin %f", x->inited_analog_pins[i]);
   }
   x->inited_analog_pins_count = 0;
}

gboolean input_digital_event(GIOChannel *channel, GIOCondition condition, gpointer user_data ){
   UNUSED_PARAMETER(condition);

   t_input* x = (t_input*)user_data;

   GError *error = 0;
   gsize bytes_read = 0;
   g_io_channel_seek_position( channel, 0, G_SEEK_SET, 0 );
   // GIOStatus rc = g_io_channel_read_chars( channel, x->digital_input_buffer, 2, &bytes_read, &error );
   g_io_channel_read_chars( channel, x->digital_input_buffer, 2, &bytes_read, &error );

   float output = 0;
   if(strcmp(x->digital_input_buffer, "1")==0){
      output = 1; 
   }

   sys_lock();
   outlet_float(x->outlet_left, output);
   sys_unlock();

   return 1;
}

void input_init_digital_pin(t_input* x, float pin_num){
   // TODO: do the actual initialization

   int fd = open("/sys/class/gpio/gpio30/value", O_RDONLY | O_NONBLOCK);
   GIOChannel* channel = g_io_channel_unix_new( fd );
   GIOCondition cond = GIOCondition(G_IO_PRI);
   // guint id = g_io_add_watch( channel, cond, input_digital_event, (gpointer)x);
   g_io_add_watch( channel, cond, input_digital_event, (gpointer)x);


   int err = 0;
   if(err){
      error("%s/input: Could not initialize digital pin number '%f'.", LIBRARY_NAME, pin_num);
   }
   else{
      debug("Inited digital pin %f", pin_num);
      x->inited_digital_pins[x->inited_digital_pins_count] = pin_num;
      x->inited_digital_pins_count ++;
   }

   if(x->digital_thread_running==0){
      input_start_digital_thread(x); 
   }
}

void input_uninit_all_digital_pins(t_input* x){
   int i=0;
   for(i=0; i<x->inited_digital_pins_count; i++){
      // TODO: do the actual uninitialization
      debug("Uninited digital pin %f", x->inited_digital_pins[i]);
   }
   x->inited_digital_pins_count = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Received PD Messages
// 

// Received "analog" message, with parameters
void input_analog(t_input* x, t_symbol* s, int argc, t_atom* argv) {
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

}

// Received "digital" message, with parameters
void input_digital(t_input* x, t_symbol* s, int argc, t_atom* argv) {
   UNUSED_PARAMETER(s);

   int i = 0;
   float pin_num;
   char* pin_str;

   input_uninit_all_digital_pins(x);
   
   // Init new pins
   for(i=0; i<argc; i++){
      // TODO: Check BB's datasheet to see which pins are good to use
      pin_num = atom_getfloatarg(i, argc, argv);
      if(pin_num==0){
         pin_str = atom_getsymbolarg(i, argc, argv)->s_name;
         error("%s/input: Digital pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, pin_str);
      }
      else{
         input_init_digital_pin(x, pin_num);
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
// Constructor, destructor
//

void *input_new(void) {
   t_input *x = (t_input *)pd_new(input_class);

   x->outlet_left = outlet_new(&x->x_obj, &s_anything);
   x->outlet_right = outlet_new(&x->x_obj, &s_anything);
   x->digital_thread_running = 0;
   x->inited_digital_pins_count = 0;
   x->analog_thread_running = 0;
   x->inited_analog_pins_count = 0;

   return (void *)x;
}

void input_free(t_input *x) { 
   input_uninit_all_digital_pins(x);
   input_stop_digital_thread(x);
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

extern "C" void input_setup(void);

void input_setup(void) {
   input_class = class_new(gensym("input"), (t_newmethod)input_new, (t_method)input_free, sizeof(t_input), CLASS_DEFAULT, (t_atomtype)0);
   class_addmethod(input_class, (t_method)input_digital, gensym("digital"), A_GIMME, 0);
   //class_addmethod(input_class, (t_method)input_analog, gensym("analog"), A_GIMME, 0);
}
