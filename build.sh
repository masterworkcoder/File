echo building test source stdio
g++ src/test/teststdio.cpp -o test -L./lib -I./include

echo building File using the SDL2 library
g++ src/test/testsdl.cpp -o testsdl -I./include -L./lib -lSDL2
