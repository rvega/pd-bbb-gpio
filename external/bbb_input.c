////////////////////////////////////////////////////////////////////////////////
// 
//  Pd-BeagleBoneBlack-Io  
//
//  Copyright (C) 2014 Rafael Vega <rvega@elsoftwarehamuerto.org>
//
//  This program is free software: you can redistribute it and/or modify it 
//  under the terms of the GNU General Public License as published by the Free 
//  Software Foundation, either version 3 of the License, or (at your option) 
//  any later version.
//  
//  This program is distributed in the hope that it will be useful, but WITHOUT 
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
//  more details.  
//  
//  You should have received a copy of the GNU General Public License along 
//  with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// TO-DO
//
// * Set analog input precision from outside message. 
//   Currently hard coded to 7 bits
//
// * Need to implement reference counting on "io" instance. We're simply
//   not freeing right now (leaking)
//
////////////////////////////////////////////////////////////////////////////////

#include "m_pd.h"

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "libbeaglebone_gpio.h"

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
   unsigned int total_delay = 0;

   #ifdef USE_ANALOG_MULTIPLEXER
   char* err;
   int mux_a, mux_b, mux_c;
   #endif

   while(1){
      for(i=0; i < x->initialized_analog_pin_count; i++){
         pin = x->initialized_analog_pins[i];
         #ifndef USE_ANALOG_MULTIPLEXER
         value = x->io->Value[pin];
         #else
         // Read regular analog input
         if(pin <= 6){
            value = x->io->Value[pin];
         }
         // Read multiplexed analog pin
         else{
            switch(pin){
               case 7:
                  mux_c = 0;
                  mux_b = 0;
                  mux_a = 0;
                  break;

               case 8:
                  mux_c = 0;
                  mux_b = 0;
                  mux_a = 1;
                  break;
                  
               case 9:
                  mux_c = 0;
                  mux_b = 1;
                  mux_a = 0;
                  break;

               case 10:
                  mux_c = 0;
                  mux_b = 1;
                  mux_a = 1;
                  break;
                  
               case 11:
                  mux_c = 1;
                  mux_b = 0;
                  mux_a = 0;
                  break;

               case 12:
                  mux_c = 1;
                  mux_b = 0;
                  mux_a = 1;
                  break;
                  
               case 13:
                  mux_c = 1;
                  mux_b = 1;
                  mux_a = 0;
                  break;
                  
               case 14:
                  mux_c = 1;
                  mux_b = 1;
                  mux_a = 1;
                  break;
                  
               default: 
                  mux_c = 0;
                  mux_b = 0;
                  mux_a = 0;
                  break;
            }

            err = pruio_gpio_out(x->io, P9_27, mux_a);
            if(err){
               error("%s/input: Could not set control pins for multiplexer. %s", LIBRARY_NAME, err);
            }
            err = pruio_gpio_out(x->io, P9_30, mux_b);
            if(err){
               error("%s/input: Could not set control pins for multiplexer. %s", LIBRARY_NAME, err);
            }
            err = pruio_gpio_out(x->io, P9_42, mux_c);
            if(err){
               error("%s/input: Could not set control pins for multiplexer. %s", LIBRARY_NAME, err);
            }

            usleep(120);
            total_delay += 120;

            value = x->io->Value[7];
         }
         #endif // USE_ANALOG_MULTIPLEXER

         // Values from ADC are 12 bits, shift right 5 places because
         // we only care for 7 bit precision.
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

         if(x->digital_values[pin] != digital_value){
            x->digital_values[pin] = digital_value; 

            pin_symbol = gensym(bbb_pin_number_to_string(pin));
            SETSYMBOL(output, pin_symbol);
            SETFLOAT(output+1, digital_value);

            sys_lock();
            outlet_list(x->outlet_left, 0, 2, output);
            sys_unlock();
         }
      }
   
      usleep(1000 - total_delay);
      total_delay = 0;
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

   // Check if device tree overlay is loaded, load if needed.
   int device_tree_overlay_loaded = 0;
   FILE*f;
   f = fopen("/sys/devices/bone_capemgr.9/slots","rt");
   if(f==NULL){
      error("%s/input: Initialisation failed (fopen rt)", LIBRARY_NAME);
      return;
   }
   char line[256];
   while(fgets(line, 256, f) != NULL){
      if(strstr(line, "PD-BBB-IO") != NULL){
         device_tree_overlay_loaded = 1;
      }
   }
   fclose(f);

   if(!device_tree_overlay_loaded){
      f = fopen("/sys/devices/bone_capemgr.9/slots","w");
      if(f==NULL){
         error("%s/input: Initialisation failed (fopen w)", LIBRARY_NAME);
         return;
      }
      fprintf(f, "PD-BBB-IO");
      fclose(f);
      usleep(100000);
   }

   // Use the same io instance always (static)
   static PruIo* io;
   if(io==NULL){
      io = pruio_new(0, 0x98, 0, 1);
      debug("Created pruio instance %i",io);
      if (io->Errr) {
         error("%s/input: Initialisation failed (%s)", LIBRARY_NAME, io->Errr);
         return;
      }
   }
   else{
      debug("Using previous puio instance %i",io);
   }
   x->io = io;

   #ifdef USE_ANALOG_MULTIPLEXER
   // Configure output pins for mux control
   if(pruio_gpio_set(x->io, P9_42, PRUIO_OUT1, PRUIO_UNLOCK_NEW)) {
      error("%s/input: Pin configuration failed (%s)\n", LIBRARY_NAME, x->io->Errr);
   }
   if(pruio_gpio_set(x->io, P9_30, PRUIO_OUT1, PRUIO_UNLOCK_NEW)) {
      error("%s/input: Pin configuration failed (%s)\n", LIBRARY_NAME, x->io->Errr);
   }
   if(pruio_gpio_set(x->io, P9_27, PRUIO_OUT1, PRUIO_UNLOCK_NEW)) {
      error("%s/input: Pin configuration failed (%s)\n", LIBRARY_NAME, x->io->Errr);
   }
   #endif //USE_ANALOG_MULTIPLEXER

   if(pruio_config(x->io, 0, 0x1FE, 0, 4, 0)){
      error("%s/input: Config failed (%s)", LIBRARY_NAME, x->io->Errr); 
   }
}

////////////////////////////////////////////////////////////////////////////////
// Init digital pins
// 
static void input_init_digital_pin(t_input* x, char* pin_str){
   unsigned int pin_num = bbb_string_to_pin_number(pin_str);
   if(pin_num == 9999){
      error("%s/input: Digital pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, pin_str);
      return;
   }

   // For some reason, setting these here, messes upthe pulldown config.  
   /* if(pruio_gpio_set(x->io, pin_num, PRUIO_IN, PRUIO_LOCK_CHECK)) {
      error("%s/input: Pin configuration failed (%s)\n", LIBRARY_NAME, x->io->Errr);
      return;
   } */

   x->initialized_digital_pins[x->initialized_digital_pin_count] = pin_num;
   x->initialized_digital_pin_count ++;
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
   // Singleton.
   static int inited;
   if(inited == 0){
      inited = 1; 
   }
   else{
      error("%s/input: You can only create one instance of this object.", LIBRARY_NAME);
      return NULL;
   }

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
   debug("Freeing",0);
   input_uninit_all_analog_pins(x);
   input_uninit_all_digital_pins(x);
   input_stop_thread(x);

   // TODO: we're leaking here... Need to implement reference counting for
   // "global" io object?
   /* pruio_destroy(x->io); */
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

void input_setup(void) {
   input_class = class_new(gensym("input"), (t_newmethod)input_new, (t_method)input_free, sizeof(t_input), CLASS_DEFAULT, (t_atomtype)0);
   class_addmethod(input_class, (t_method)input_digital, gensym("digital"), A_GIMME, 0);
   class_addmethod(input_class, (t_method)input_analog, gensym("analog"), A_GIMME, 0);
}
