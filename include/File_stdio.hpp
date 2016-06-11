#ifndef FILE_STDIO_HPP
#define FILE_STDIO_HPP

#include <stdio.h>
#include "File_Struct.hpp"

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
  f_File* getFilePtr(); // returns a pointer to the file object
  const char* getError(); // currently just returns NULL
private:
  f_File* f_file;

};

#endif // FILE_STDIO_HPP
