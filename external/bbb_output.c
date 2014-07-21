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

#include "m_pd.h"
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "libbeaglebone_gpio.h"

////////////////////////////////////////////////////////////////////////////////
// Data
//

typedef struct output {
   t_object x_obj;
   PruIo* io;
   unsigned int initialized_digital_pin_count;
   unsigned int initialized_digital_pins[MAX_DIGITAL_PINS];
} t_output;

// A pointer to the class object.
t_class *output_class;

////////////////////////////////////////////////////////////////////////////////
// Init digital pins
// 
static void output_init_digital_pin(t_output* x, char* pin_str){
   unsigned int pin_num = bbb_string_to_pin_number(pin_str);
   if(pin_num == 9999){
      error("%s/output: Digital pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, pin_str);
      return;
   }

   if(pruio_gpio_set(x->io, pin_num, PRUIO_OUT0, PRUIO_LOCK_CHECK)) {
      error("%s/output: Pin configuration failed (%s)\n", LIBRARY_NAME, x->io->Errr);
      return;
   }

   x->initialized_digital_pins[x->initialized_digital_pin_count] = pin_num;
   x->initialized_digital_pin_count ++;
   debug2("Inited digital pin %s (%u)", pin_str, pin_num);
}

static void output_uninit_all_digital_pins(t_output* x){
   unsigned int i;
   for(i=0; i<x->initialized_digital_pin_count; i++){
      x->initialized_digital_pins[i] = 9999;
      debug("Uninited digital pin %u", x->initialized_digital_pins[i]);
   }
   x->initialized_digital_pin_count = 0;
}

static void output_init_gpio(t_output* x){
   // Check if device tree overlay is loaded, load if needed.
   int device_tree_overlay_loaded = 0;
   FILE*f;
   f = fopen("/sys/devices/bone_capemgr.9/slots","rt");
   if(f==NULL){
      error("%s/output: Initialisation failed (fopen rt)", LIBRARY_NAME);
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
         error("%s/output: Initialisation failed (fopen w)", LIBRARY_NAME);
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
         error("%s/output: Initialisation failed (%s)", LIBRARY_NAME, io->Errr);
         return;
      }
   }
   else{
      debug("Using previous puio instance %i",io);
   }
   x->io = io;
}

////////////////////////////////////////////////////////////////////////////////
// Received PD Messages
// 

// Received "digital" message, with parameters
static void output_digital(t_output* x, t_symbol* s, int argc, t_atom* argv) {
   UNUSED_PARAMETER(s);

   int i = 0;
   char* pin_str;

   output_uninit_all_digital_pins(x);
   
   // Init new pins
   for(i=0; i<argc; i++){
      pin_str = atom_getsymbolarg(i, argc, argv)->s_name;
      output_init_digital_pin(x, pin_str);
   }

   // "Finalize" pin config.
   if(pruio_config(x->io, 0, 0x1FE, 0, 4, 0)){
      error("%s/output: Config failed (%s)", LIBRARY_NAME, x->io->Errr); 
   }
}

// Received a message like [P9_11 1(
static void output_message(t_output* x, t_symbol* s, int argc, t_atom* argv) {
   unsigned int pin_number = bbb_string_to_pin_number(s->s_name);
   int pin_is_inited = 0;
   unsigned int i;

   if(pin_number==9999){
      error("%s/output: Digital pin number '%s' is invalid. Ignoring.", LIBRARY_NAME, s->s_name);
      return;
   }

   for(i=0; i<x->initialized_digital_pin_count; i++) {
      if(x->initialized_digital_pins[i] == pin_number){
         pin_is_inited = 1;   
      }
   }
   if(!pin_is_inited){
      error("%s/output: Digital pin number '%s' has not been initialized. Ignoring.", LIBRARY_NAME, s->s_name);
      return;
   }

   int value = atom_getintarg(0, argc, argv);
   if(value != 1) value = 0;
   pruio_gpio_out(x->io, pin_number, value);
}

///////////////////////////////////////////////////////////////////////////////
// Constructor, destructor
//

static void *output_new(void) {
   t_output *x = (t_output *)pd_new(output_class);

   int i;
   x->initialized_digital_pin_count = 0;
   for (i=0; i<MAX_DIGITAL_PINS; i++) {
      x->initialized_digital_pins[i]=9999;
   }

   output_init_gpio(x);
   return (void *)x;
}

static void output_free(t_output *x) { 
   debug("Freeing",0);
   output_uninit_all_digital_pins(x);

   // TODO: we're leaking here... Need to implement reference counting for
   // "global" io object?
   /* pruio_destroy(x->io); */
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

void output_setup(void) {
   output_class = class_new(gensym("output"), (t_newmethod)output_new, (t_method)output_free, sizeof(t_output), CLASS_DEFAULT, (t_atomtype)0);
   class_addmethod(output_class, (t_method)output_digital, gensym("digital"), A_GIMME, 0);
   class_addanything(output_class, output_message);
}
