echo building File with stdio
g++ -c src/lib/File_stdio.cpp -I./include -o File1.o
g++ -c src/lib/File_sdl.cpp -I./include -o File2.o -lSDL2
ar rscv lib/libFile.a File1.o File2.o
rm File1.o
rm File2.o

echo building test source stdio
g++ src/test/teststdio.cpp -o test -L./lib -I./include -lFile

echo building File using the SDL2 library
g++ src/test/testsdl.cpp -o testsdl -I./include -L./lib -lFile
