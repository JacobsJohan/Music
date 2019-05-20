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

#ifndef INCLUDED_CUSTOM_ARG_TO_COMPLEX_IMPL_H
#define INCLUDED_CUSTOM_ARG_TO_COMPLEX_IMPL_H

#include <custom/Arg_to_Complex.h>

namespace gr {
  namespace custom {

    class Arg_to_Complex_impl : public Arg_to_Complex
    {
     private:
      // Nothing to declare in this block.

     public:
      Arg_to_Complex_impl();
      ~Arg_to_Complex_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace custom
} // namespace gr

#endif /* INCLUDED_CUSTOM_ARG_TO_COMPLEX_IMPL_H */

