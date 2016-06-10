#ifndef FILE_HPP
#define FILE_HPP

#ifdef FILE_SDL
#include "File_SDL.hpp"
#else
#include "File_stdio.hpp"
#endif // FILE_SDL

#endif // FILE_HPP
