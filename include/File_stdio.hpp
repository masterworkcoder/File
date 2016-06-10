#ifndef FILE_STDIO_HPP
#define FILE_STDIO_HPP

#include <stdio.h>

class File
{
public:
  File();
  ~File();
  bool load(const char* filename, const char* mode);
  bool isOpen();
  bool read(char* buffer, int size, int numread = 1);
  bool write(char* buffer, int size, int numwrite = 1);
  void close();
  size_t getSize();
  FILE* getFilePtr();
  const char* getError();
private:
  FILE* f_file;

};

#endif // FILE_STDIO_HPP
