// handler.cpp
#include "handler.h"

void parseInput(int argc, char *argv[])
{
	std::string current_exec_name = argv[0]; // Name of the current exec program
	std::vector<std::string> all_args;

	if (argc > 1)
	{
		all_args.assign(argv + 1, argv + argc);
	}

	for (int i = 0; i < all_args.size(); ++i)
	{
		std::cout << all_args[i] << std::endl;
	}
}

void Tests(){
	// Echo echo;
	// echo.ProcessLine("Hellow");
	// echo.HandleEndOfInput();

	// Cat cat;
	// cat.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
	// cat.HandleEndOfInput();

	// WC wc;
	// wc.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
}