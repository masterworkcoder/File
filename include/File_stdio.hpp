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
  File();
  ~File();
  bool load(const char* filename, const char* mode); // loads a file mode can be any of the usual modes returns true on success
  bool isOpen(); // simply checks to see if the file is open returns true if open
  bool read(char* buffer, int size, int numread = 1); // reads from the file
  char getC(); // gets the next character
  char peekC(); // gets the next character without changing the position in the file
  bool seek(size_t pos, int from); // seeks a position from the desired point
  bool write(char* buffer, int size, int numwrite = 1); // writes to the file
  void close(); // closes the file if the file is open
  size_t getSize(); // returns the size of the file
  f_File* getFilePtr(); // returns a pointer to the file object
  const char* getError(); // currently just returns NULL
private:
  f_File* f_file;

};

#endif // FILE_STDIO_HPP
