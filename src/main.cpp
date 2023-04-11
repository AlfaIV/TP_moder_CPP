#include <CLIcommands.h>
#include <handler.h>


int main(int argc, char *argv[])
{
	std::vector<std::string> inputPipeline;
	std::queue<std::string> inputBuffer;
	inputPipeline = parseInput(argc, argv);
	for (int i = 0; i < inputPipeline.size(); i += 1)
		std::cout << inputPipeline[i] << " ";
	std::cout << std::endl;
	// Tests();

	inputBuffer.push("sdfsd");
	inputBuffer.push("вапва");
	WcL wc(inputPipeline, inputBuffer);
	// wc.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
	wc.HandleEndOfInput();

	// std::cout << "Hellow world" << std::endl;
	return 0;
}