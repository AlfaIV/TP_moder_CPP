// CLIcommands.h
#ifndef CLI_COMMANDS
#define CLI_COMMANDS

#include <string>
#include <iostream>
#include <fstream>
// using namespace std;

class IOperation
{
public:
    void ProcessLine(const std::string &str);
    virtual void HandleEndOfInput() = 0;
    // virtual void SetNextOperation(<умный/сырой указатель/ссылка на IOperation>) = 0;
};

class Echo : IOperation
{
public:
    void ProcessLine(const std::string &str);
    void HandleEndOfInput();
};

class Cat : IOperation
{
public:
    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
};

class WcL : IOperation
{
public:
    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
};

#endif
