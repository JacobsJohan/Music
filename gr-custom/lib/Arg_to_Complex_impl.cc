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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Arg_to_Complex_impl.h"
#include <math.h>
#include <complex>
#include <cmath>


namespace gr {
  namespace custom {

    Arg_to_Complex::sptr
    Arg_to_Complex::make()
    {
      return gnuradio::get_initial_sptr
        (new Arg_to_Complex_impl());
    }

    /*
     * The private constructor
     */
    Arg_to_Complex_impl::Arg_to_Complex_impl()
      : gr::sync_block("Arg_to_Complex",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    Arg_to_Complex_impl::~Arg_to_Complex_impl()
    {
    }

    int
    Arg_to_Complex_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      // Do <+signal processing+>
      std::complex<double> j = 1i;
      for (int k = 0; k < noutput_items; k++) {
        out[k] = exp(j*double(in[k]));
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace custom */
} /* namespace gr */

