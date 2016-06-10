# File
A small class for making it a little easier to load files using either SDL_RWops or stdio.h functionallity. It is cross platform
and ready to go. I have only test on linux thus far, but will be building on windows soon.

##Origin
This class came about while learning about game engine development and I decided I wanted to use it in my petcode projects lexer.
It continues to gain new features and functionality.

##Building
To build this library since there are two different parts stdio and SDL2's rwops if you have the SDL2 libraries setup
and ready to go you can just execute the build.sh file (linux only). It will create a library file and put it in the folder.

If you don't have SDL2 installed but still want to use the library refer execute the following
```bash
g++ -c src/lib/File.cpp -I./include -o File.o
ar rc lib/libFile.a File.o
```
Then to build the test file perform the following
```bash
g++ src/test/main.cpp -o test -I./include -I./lib -lFile
```

##Usage
when you include the file to use the SDL system you need to define FILE_SDL
```c++
#define FILE_SDL
#include "File.hpp"
```
For more information until I have the documentation pounded out check out the header files and source code.

##TO-DO
* convert the comments into documentation
* create a more efficient build system
* add more features and functionality


####Licesne
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
