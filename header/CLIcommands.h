// CLIcommands.h
#ifndef CLI_COMMANDS
#define CLI_COMMANDS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

class IOperation
{
public:
    std::vector<std::string> pipeline;
    //содержит текущую и последующие команды
    std::queue<std::string> buffer;
    //храниться буффер на вывод

    // IOperation(std::vector<std::string> &inputPipeline);

    virtual void ProcessLine(const std::string &str) = 0;
    //выполняет команду
    virtual void HandleEndOfInput() = 0;
    //обрабатывает пайплайн
    virtual void SetNextOperation(IOperation nextOp) = 0;
    //либо передает буффер на вывод, либо следующей команде
};


#endif

