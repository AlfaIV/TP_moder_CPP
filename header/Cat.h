// Cat.h
#ifndef CAT
#define CAT

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include <CLIcommands.h>
#include <Wcl.h>
#include <Echo.h>

class Cat : public IOperation
{
public:
    Cat(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer);

    void ProcessLine(const std::string &nameOfFile);
    void HandleEndOfInput();
    void SetNextOperation(IOperation &nextOp);
};
#endif