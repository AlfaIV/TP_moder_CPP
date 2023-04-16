// Echo.h
#ifndef ECHO
#define ECHO

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include <CLIcommands.h>
#include <Wcl.h>
#include <Cat.h>

// class IOperation;
class Echo : public IOperation
{
public:
    Echo(std::vector<std::string> &inputPipeline);

    void ProcessLine(const std::string &str);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};

#endif