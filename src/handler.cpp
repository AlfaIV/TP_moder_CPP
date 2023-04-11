// handler.cpp
#include "handler.h"

std::vector<std::string> parseInput(int argc, char *argv[])
{
	std::string current_exec_name = argv[0]; // Name of the current exec program
	std::vector<std::string> allArgs;

	if (argc > 1)
	{
		allArgs.assign(argv + 1, argv + argc);
	}

	// for (int i = 0; i < allArgs.size(); ++i)
	// {
	// 	std::cout << allArgs[i] << std::endl;
	// }
	std::vector<std::string> parseString;
	tokenize(allArgs[0], ' ', parseString);
	// for (int i = 0; i < parseString.size(); i += 1)
	// 	std::cout << parseString[i] << " ";

	return parseString;
}

void tokenize(std::string const &str,
			  const char delim,
			  std::vector<std::string> &out)
{
	// парсинг строки на слова
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim))
	{
		out.push_back(s);
	}
}

void Tests(int argc, char *argv[])
{
	// Echo echo;
	// echo.ProcessLine("Hellow");
	// echo.HandleEndOfInput();

	// Cat cat;
	// cat.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
	// cat.HandleEndOfInput();

	// WcL wc;
	// wc.ProcessLine("/home/alfaiv/Code/TP_VK/modern_cpp/HM1/build/Test.txt");
	// wc.HandleEndOfInput();

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
}