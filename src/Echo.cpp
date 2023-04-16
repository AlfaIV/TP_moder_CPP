#include <Echo.h>

//-----------------------------------------------------------
// echo
Echo::Echo(std::vector<std::string> &inputPipeline)
{
    this->pipeline = inputPipeline;
}

void Echo::ProcessLine(const std::string &str)
{
    // std::cout << "Echo: " << str << std::endl;
    this->buffer.push(str);
    std::cout << this->buffer.front() << std::endl;
}

void Echo::HandleEndOfInput()
{
    if (this->pipeline.size() >= 2 && this->pipeline[0] == "echo")
    {
        // std::cout << this->pipeline[3] << std::endl;
        this->ProcessLine(this->pipeline[1]);
        // обработка текущей команды

        if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "echo")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            // Echo echo(this->pipeline);
            // IOperation &NextOp = echo;
            // // echo.HandleEndOfInput();
            // this->SetNextOperation(echo);

            std::cout << "Echo" << std::endl;
        }
        else if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "cat")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            // Cat cat(this->pipeline, this->buffer);
            // IOperation &NextOp = cat;
            // // cat.HandleEndOfInput();
            // this->SetNextOperation(cat);

            std::cout << "Cat" << std::endl;
        }
        else if (this->pipeline.size() >= 4 && this->pipeline[2] == "|" && this->pipeline[3] == "wc")
        {
            this->pipeline.erase(pipeline.begin(), pipeline.begin() + 3);
            // std::cout << pipeline[0] << std::endl;

            // WcL wcl(this->pipeline, this->buffer);
            // IOperation &NextOp = wcl;
            // // wcl.HandleEndOfInput();
            // this->SetNextOperation(wcl);

            std::cout << "wc" << std::endl;
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

void Echo::SetNextOperation(IOperation &nextOp)
{
    nextOp.HandleEndOfInput();
}