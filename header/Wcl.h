// Wcl.h
#ifndef WCL
#define WCL

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include <CLIcommands.h>
#include <Cat.h>
#include <Echo.h>

class WcL : public IOperation
{
public:
    WcL(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer);

    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};

#endif