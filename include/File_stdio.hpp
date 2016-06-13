// File/File_stdio.hpp
/*********************************************************************************
MIT License

Copyright (c) 2016 Aaron McKinney

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
********************************************************************************/

#ifndef FILE_STDIO_HPP
#define FILE_STDIO_HPP

#include <cstdio>
#include "File_Struct.hpp"

class File
{
public:
  File(): f_file(NULL) {}
  ~File() { this->close(); }

  bool load(const char* filename, const char* mode) // loads a file mode can be any of the usual modes returns true on success
  {
    f_file = fopen(filename, mode);
    if(this->isOpen())
      return true;
    return false;
  }

  bool isOpen() // simply checks to see if the file is open returns true if open
  {
    if(f_file == NULL)
      return false;
    return true;
  }

  bool read(char* buffer, int size, int numread = 1) // reads from the file
  {
    if(fread(buffer, size, numread, f_file) > 0)
      return true;
    return false;
  }

  char getC() // gets the next character
  {
    char c = fgetc(f_file);
    return c;
  }

  char peekC() // gets the next character without changing the position in the file
  {
    char c = this->getC();
    if(this->seek(-1, FILE_CUR))
      return c;
  }

  bool seek(size_t pos, int from) // seeks a position from the desired point
  {
    if(!this->isOpen())
      return false;
    if(fseek(f_file, pos, from) > 0)
      return false;
    return true;
  }

  bool write(char* buffer, int size, int numwrite = 1) // writes to the file
  {
    if(fwrite(buffer, size, numwrite, f_file) < numwrite)
      return false;
    return true;
  }

  void close() // closes the file if the file is open
  {
    if(this->isOpen())
    {
      fclose(f_file);
      f_file = NULL;
    }
  }

  size_t getSize() // returns the size of the file
  {
    if(!this->isOpen())
      return 0;
    size_t cur_pos = ftell(f_file);
    if(!this->seek(0, FILE_END))
      return 0;
    size_t size = ftell(f_file);
    if(!this->seek(cur_pos, FILE_START))
      return -1;
    return size;
  }

  f_File* getFilePtr() // returns a pointer to the file object
  {
    return f_file;
  }

  const char* getError() // currently just returns NULL
  {
    return NULL;
  }
  
private:
  f_File* f_file;

};

#endif // FILE_STDIO_HPP
