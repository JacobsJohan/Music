INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_MUSIC Music)

FIND_PATH(
    MUSIC_INCLUDE_DIRS
    NAMES Music/api.h
    HINTS $ENV{MUSIC_DIR}/include
        ${PC_MUSIC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    MUSIC_LIBRARIES
    NAMES gnuradio-Music
    HINTS $ENV{MUSIC_DIR}/lib
        ${PC_MUSIC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(MUSIC DEFAULT_MSG MUSIC_LIBRARIES MUSIC_INCLUDE_DIRS)
MARK_AS_ADVANCED(MUSIC_LIBRARIES MUSIC_INCLUDE_DIRS)

