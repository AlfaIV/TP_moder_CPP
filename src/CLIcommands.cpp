// CLIcommands.cpp
#include "CLIcommands.h"

void IOperation(std::vector<std::string> inputPipeline, std::queue<std::string> buffer)
{
    std::cout << inputPipeline[0] << std::endl;
}

//-----------------------------------------------------------
// echo

void Echo::ProcessLine(const std::string &str)
{
    std::cout << "Echo: " << str << std::endl;
}

void Echo::HandleEndOfInput()
{
    std::cout << "Echo: "
              << "HandleEndOfInput" << std::endl;
}

//-----------------------------------------------------------
// cat

void Cat::HandleEndOfInput()
{
    std::cout << "Cat: "
              << "HandleEndOfInput" << std::endl;
}

void Cat::ProcessLine(const std::string &nameOfFile)
{

    std::string line;

    std::ifstream in(nameOfFile); // окрываем файл для чтения
    if (in.is_open())
    {
        std::cout << "Cat: "
                  << "File Is Open" << std::endl;
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Cat: "
                  << "Sorry File Is Not Open" << std::endl;
    }
    in.close(); // закрываем файл
}

//-----------------------------------------------------------
// wc

WcL::WcL(std::vector<std::string> &inputPipeline, std::queue<std::string> &inputBuffer)
{
    this->pipeline = inputPipeline;
    // std::cout << inputPipeline[0] << std::endl;
    while(!inputBuffer.empty()){
        this->buffer.push(inputBuffer.front());
        inputBuffer.pop();
    }
    std::cout << this->buffer.size() << std::endl;
}

void WcL::ProcessLine(const std::string &nameOfFile)
{
    double counter = 0;
    std::string line;

    std::ifstream in(nameOfFile); // окрываем файл для чтения
    if (in.is_open())
    {
        std::cout << "Cat: "
                  << "File Is Open" << std::endl;
        while (getline(in, line))
        {
            counter += 1;
        }
    }
    else
    {
        std::cout << "Cat: "
                  << "Sorry File Is Not Open" << std::endl;
    }

    std::cout << counter << std::endl;
    this->buffer.push(std::to_string(counter));
    in.close(); // закрываем файл
}

void WcL::HandleEndOfInput()
{
    if(this->pipeline.size() == 2){
        std::cout << this->pipeline[1] << std::endl;
        this->ProcessLine(this->pipeline[1]);
    }
}