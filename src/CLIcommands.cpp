// CLIcommands.cpp
#include "CLIcommands.h"

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


void WC::ProcessLine(const std::string &nameOfFile)
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
    in.close(); // закрываем файл
}