// CLIcommands.cpp
#include "CLIcommands.h"

//-----------------------------------------------------------
// echo
Echo::Echo(std::vector<std::string> &inputPipeline)
{
    this->pipeline = inputPipeline;
}

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

Cat::Cat(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer)
{
    this->pipeline = inputPipeline;
    // std::cout << inputPipeline[0] << std::endl;
    while (!inputBuffer.empty())
    {
        this->buffer.push(inputBuffer.front());
        inputBuffer.pop();
    }
    // std::cout << this->buffer.size() << std::endl;
}

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

WcL::WcL(std::vector<std::string> &inputPipeline, std::queue<std::string> inputBuffer)
{
    this->pipeline = inputPipeline;
    // std::cout << inputPipeline[0] << std::endl;
    while (!inputBuffer.empty())
    {
        this->buffer.push(inputBuffer.front());
        inputBuffer.pop();
    }
    // std::cout << this->buffer.size() << std::endl;
}

void WcL::ProcessLine(const std::string &nameOfFile)
{
    // считаем количество строк
    double counter = 0;
    std::string line;

    std::ifstream in(nameOfFile);
    // окрываем файл для чтения
    if (in.is_open())
    {
        // std::cout << "Cat: "
        //           << "File Is Open" << std::endl;
        while (getline(in, line))
        {
            counter += 1;
        }
    }
    else
    {
        // std::cout << "Cat: "
        //           << "Sorry File Is Not Open" << std::endl;
    }

    // std::cout << counter << std::endl;
    this->buffer.push(std::to_string(counter));
    // std::cout << this->buffer.back() << std::endl;
    // записываем посчитанное количество в буффер
    in.close();
    // закрываем файл
}

void WcL::HandleEndOfInput()
{
    if (this->pipeline.size() >= 2 && this->pipeline[0] == "wc")
    {
        // std::cout << this->pipeline[3] << std::endl;
        this->ProcessLine(this->pipeline[1]);
        // обработка текущей команды

        if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "echo")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            Echo echo(this->pipeline);
            IOperation &NextOp = echo;
            echo.HandleEndOfInput();
            // void SetNextOperation(echo);

            std::cout << "Echo" << std::endl;
        }
        else if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "cat")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            Cat cat(this->pipeline, this->buffer);
            IOperation &NextOp = cat;
            cat.HandleEndOfInput();
            // void SetNextOperation(echo);

            std::cout << "Cat" << std::endl;
        }
        else if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "ws")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            WcL wcl(this->pipeline, this->buffer);
            IOperation &NextOp = wcl;
            wcl.HandleEndOfInput();
            // void SetNextOperation(echo);

            std::cout << "Cat" << std::endl;
        }
        else
        {
            while (!buffer.empty())
            {
                std::cout << buffer.front() << std::endl;
                buffer.pop();
            }
        }
    }
}

// void WcL::SetNextOperation(IOperation nextOp){
//     std::cout << "WcL" << " " << "SetNextOperation" << std::endl;
// }
