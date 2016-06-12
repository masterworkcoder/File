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

#define FILE_SDL
#include <File.hpp>

File::File()
{
  f_file = NULL;
} // File()

File::~File()
{
  this->close();
} // ~File()

bool File::load(const char* filename, const char* mode)
{
  f_file = SDL_RWFromFile(filename, mode);
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
  if(SDL_RWread(f_file, buffer, size, numread) > 0)
    return true;
  return false;
} // read()

char File::getC()
{
  char character;
  this->read(&character, 1, 1);
  return character;
} // getC()

char File::peekC()
{
  size_t cur_pos = SDL_RWtell(f_file);
  char character = this->getC();
  if(this->seek(cur_pos, FILE_START))
    return character;
} // peekC()

bool File::seek(size_t pos, int from)
{
  if(!this->isOpen())
    return false;
  if(from == FILE_START)
    if(SDL_RWseek(f_file, pos, RW_SEEK_SET) == -1)
      return false;
  else if(from == FILE_CUR)
    if(SDL_RWseek(f_file, pos, RW_SEEK_CUR) == -1)
      return false;
  else if(from == FILE_END)
    if(SDL_RWseek(f_file, pos, RW_SEEK_END))
      return false;
  return true;
} // seek()

bool File::write(char* buffer, int size, int numwrite)
{
  if(SDL_RWwrite(f_file, buffer, size, numwrite) < numwrite)
  {
    return false;
  }
  return true;
} // write()

void File::close()
{
  if(this->isOpen())
  {
    SDL_RWclose(f_file);
    f_file = NULL;
  }
} // destroy()

f_File* File::getFilePtr()
{
  return f_file;
} // getFilePtr()

size_t File::getSize()
{
  return SDL_RWsize(f_file);
} // getSize()

const char* File::getError()
{
  return SDL_GetError();
} // getError()
