# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file was generated by gr_modtool, a tool from the GNU Radio framework
# This file is a part of gr-Music
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

list(APPEND Music_sources
    music_impl.cc
)

set(Music_sources "${Music_sources}" PARENT_SCOPE)
if(NOT Music_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT Music_sources)

add_library(gnuradio-Music SHARED ${Music_sources})
target_link_libraries(gnuradio-Music ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES} ${ARMADILLO_LIBRARIES})
set_target_properties(gnuradio-Music PROPERTIES DEFINE_SYMBOL "gnuradio_Music_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-Music PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-Music RUNTIME_COMPONENT "Music_runtime" DEVEL_COMPONENT "Music_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_Music_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_Music.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_Music.cc
)

add_executable(test-Music ${test_Music_sources})

target_link_libraries(
  test-Music
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-Music
)

GR_ADD_TEST(test_Music test-Music)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

