/* -*- c++ -*- */
/* 
 * Copyright 2019 Johan Jacobs.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_MUSIC_MUSIC_IMPL_H
#define INCLUDED_MUSIC_MUSIC_IMPL_H

#include <Music/music.h>

namespace gr {
  namespace Music {

    class music_impl : public music
    {
     private:
      int d_numAnt;
      int d_numSamp;
      int d_numSrc;
      float d_distance;
      float d_freq;
      float d_accuracy;

     public:
      music_impl(int numAnt, int numSamp, int numSrc, float distance, float freq, float accuracy);
      ~music_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Music
} // namespace gr

#endif /* INCLUDED_MUSIC_MUSIC_IMPL_H */

