// handler.cpp
#include "handler.h"
// #include "CLIcommands.cpp"
// #include "Echo.cpp"
// #include "Cat.cpp"

std::vector<std::string> parseInput(int argc, char *argv[])
{
	std::string current_exec_name = argv[0];
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

void processPipline(std::vector<std::string> inputPipeline)
{
	if (!inputPipeline.empty())
	{
		std::queue<std::string> inputBuffer;
		if (inputPipeline[0] == "echo")
		{
			Echo echo(inputPipeline);
			echo.HandleEndOfInput();
			// std::cout << "Echo" << std::endl;
		}
		else if (inputPipeline[0] == "cat")
		{
			Cat cat(inputPipeline, inputBuffer);
			cat.HandleEndOfInput();
			// std::cout << "Cat" << std::endl;
		}
		else if (inputPipeline[0] == "wc")
		{
			WcL wcl(inputPipeline, inputBuffer);
			wcl.HandleEndOfInput();

			// std::cout << "wc" << std::endl;
		}
	}
}

void handler(int argc, char *argv[])
{
	std::vector<std::string> inputPipeline;
	std::queue<std::string> inputBuffer;
	inputPipeline = parseInput(argc, argv);
	for (int i = 0; i < inputPipeline.size(); i += 1)
		std::cout << inputPipeline[i] << " ";
	std::cout << std::endl;
	processPipline(inputPipeline);
}