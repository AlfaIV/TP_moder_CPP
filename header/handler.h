// handler.h

#ifndef HANDLER
#define HANDLER

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <CLIcommands.h>
// using namespace std;

std::vector<std::string> parseInput(int argc, char *argv[]);
void Tests(int argc, char *argv[]);
void tokenize(std::string const &str,
              const char delim,
              std::vector<std::string> &out);

#endif
