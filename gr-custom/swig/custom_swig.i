/* -*- c++ -*- */

#define CUSTOM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "custom_swig_doc.i"

%{
#include "custom/Arg_to_Complex.h"
%}


%include "custom/Arg_to_Complex.h"
GR_SWIG_BLOCK_MAGIC2(custom, Arg_to_Complex);
