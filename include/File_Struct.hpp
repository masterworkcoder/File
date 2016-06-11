#ifndef FILE_STRUCTURE_HPP
#define FILE_STRUCTURE_HPP

#ifdef FILE_SDL
#if __cplusplus > 199711L
using f_File = SDL_RWops;
#else
typedef SDL_RWops f_File;
#endif
#else
#if __cplusplus > 199711L
using f_File = FILE;
#else
typedef FILE f_File;
#endif
#endif

#endif // FILE_STRUCTURE_HPP
