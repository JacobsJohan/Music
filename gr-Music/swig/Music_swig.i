/* -*- c++ -*- */

#define MUSIC_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Music_swig_doc.i"

%{
#include "Music/music.h"
%}


%include "Music/music.h"
GR_SWIG_BLOCK_MAGIC2(Music, music);
