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

#include <File.hpp>

File::File()
{
  f_file = NULL;
} // File()

File::~File()
{
  close();
} // ~File()

bool File::load(const char* filename, const char* mode)
{
  f_file = fopen(filename, mode);
  if(f_file == NULL)
  {
    return false;
  }
  return true;
} // load()

bool File::isOpen()
{
  if(f_file != NULL)
    return true;
  return false;
} // isOpen()

bool File::read(char* buffer, int size, int numread)
{
  if(fread(buffer, size, numread, f_file) > 0)
    return true;
  return false;
} // read()

bool File::write(char* buffer, int size, int numwrite)
{
  if(fwrite(buffer, size, numwrite, f_file) < numwrite)
  {
    return false;
  }
  return true;
} // write()

void File::close()
{
  if(isOpen())
  {
    fclose(f_file);
    f_file = NULL;
  }
} // destroy()

FILE* File::getFilePtr()
{
  return f_file;
} // getFilePtr()

size_t File::getSize()
{
  size_t cur_pos = ftell(f_file);
  if(fseek(f_file, 0, SEEK_END) !=0)
    return 0;
  size_t size = ftell(f_file);
  if(fseek(f_file, cur_pos, SEEK_SET) != 0)
    return 0;
  return size;
} // getSize()

const char* File::getError()
{
  return NULL;
} // getError()
