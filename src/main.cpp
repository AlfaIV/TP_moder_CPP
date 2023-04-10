#include <CLIcommands.h>

int main(int argc, char *argv[])
{
	// Echo echo;
	// echo.ProcessLine("Hellow");
	// echo.HandleEndOfInput();

	// Cat cat;
	// cat.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
	// cat.HandleEndOfInput();

	WC wc;
	wc.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");

	std::cout << "Hellow world" << std::endl;
	return 0;
}