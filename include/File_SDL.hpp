#ifndef FILE_SDL_HPP
#define FILE_SDL_HPP

#include <SDL2/SDL_rwops.h>

class File
{
public:
  File();
  ~File();
  bool load(const char* filename, const char* mode); // loads a file mode can be any of the usual modes returns true on success
  bool isOpen(); // simply checks to see if the file is open returns true if open
  bool read(char* buffer, int size, int numread = 1); // reads from the file
  bool write(char* buffer, int size, int numwrite = 1); // writes to the file
  void close(); // closes the file if the file is open
  size_t getSize(); // returns the size of the file
  SDL_RWops* getFilePtr(); // returns a pointer to the file object
  const char* getError(); // returns a pointer to the error contents
private:
  SDL_RWops* f_file;

};

#endif // FILE_SDL_HPP
