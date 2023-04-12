// handler.h

#ifndef HANDLER
#define HANDLER

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// using namespace std;

std::vector<std::string> parseInput(int argc, char *argv[]);
void handler(int argc, char *argv[]);
void tokenize(std::string const &str,
              const char delim,
              std::vector<std::string> &out);
void processPipline(std::vector<std::string> inputPipeline);

#endif
