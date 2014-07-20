#include "m_pd.h"

#define MAX_LIST_SIZE 256

////////////////////////////////////////////////////////////////////////////////
// Data
//

// State variables in a struct 
typedef struct output {

   t_object x_obj;

   // float list_right[MAX_LIST_SIZE];
   // int list_right_length;

} t_output;

// A pointer to the class object.
t_class *output_class;

////////////////////////////////////////////////////////////////////////////////
// Methods
// 

// Received a list on left inlet.
static void output_left_inlet(t_output* x, t_symbol* s, int argc, t_atom* argv) {
   (void)s;

   // Get floats in inlet list;
   // int i,j;
   // int list_left_length = argc;
   // float list_left[MAX_LIST_SIZE];
   // for(i=0; i<argc; i++){
   //    list_left[i] = atom_getfloatarg(i, argc, argv);
   // }

}


///////////////////////////////////////////////////////////////////////////////
// Constructor, destructor
//

static void *output_new(void) {
   t_output *x = (t_output *)pd_new(output_class);
   return (void *)x;
}

static void output_free(t_output *x) { 
   (void)x;
}

///////////////////////////////////////////////////////////////////////////////
// Class definition
// 

void output_setup(void) {
   output_class = class_new(gensym("output"), (t_newmethod)output_new, (t_method)output_free, sizeof(t_output), 0, (t_atomtype)0);
   class_addlist(output_class, output_left_inlet);
}
