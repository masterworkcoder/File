#include <iostream>
#include <File.hpp>

int main(int argc, char* argv[])
{
	File file;
	if(argc == 2)
	{
		file.load(argv[1], "r");
		int size = file.getSize();
		char* buffer = new char[size+1];
		file.read(buffer, size, 1);
		std::cout << buffer << std::endl;
		delete[] buffer;
		buffer = NULL;
	}
	else
	{
		std::cout << "I require one argument a file to printed to screen" << std::endl;
	}
	return 0;
}
