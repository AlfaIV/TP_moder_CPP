#include <CLIcommands.h>
#include <handler.h>

int main(int argc, char *argv[])
{
	// parseInput(argc, argv);
	// Tests();

	WcL wc;
	// wc.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
    wc.HandleEndOfInput();

	std::cout << "Hellow world" << std::endl;
	return 0;
}