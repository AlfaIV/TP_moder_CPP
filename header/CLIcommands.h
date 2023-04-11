// CLIcommands.h
#ifndef CLI_COMMANDS
#define CLI_COMMANDS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

// using namespace std;

class IOperation
{
public:
    std::vector<std::string> pipeline;
    //содержит текущую и последующие команды
    std::queue<std::string> buffer;
    //храниться буффер на вывод

    virtual void ProcessLine(const std::string &str) = 0;
    //выполняет команду
    virtual void HandleEndOfInput() = 0;
    //обрабатывает пайплайн
    // virtual SetNextOperation(IOperation nextOp) = 0;
    //либо передает буффер на вывод, либо следующей команде
};

class Echo : public IOperation
{
public:
    Echo(std::vector<std::string> &inputPipeline);

    void ProcessLine(const std::string &str);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};

class Cat : public IOperation
{
public:
    Cat(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer);

    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};

class WcL : public IOperation
{
public:
    WcL(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer);

    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};

#endif

