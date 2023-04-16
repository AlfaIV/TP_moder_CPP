#include <Cat.h>
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
    if (this->pipeline.size() >= 2 && this->pipeline[0] == "cat")
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

void Cat::ProcessLine(const std::string &nameOfFile)
{

    std::string line;

    std::ifstream in(nameOfFile); // окрываем файл для чтения
    if (in.is_open())
    {
        // std::cout << "Cat: "
        //           << "File Is Open" << std::endl;
        while (getline(in, line))
        {
            // std::cout << line << std::endl;
            this->buffer.push(line);
        }
    }
    else
    {
        // std::cout << "Cat: "
        //           << "Sorry File Is Not Open" << std::endl;
    }
    in.close(); // закрываем файл
}

void Cat::SetNextOperation(IOperation &nextOp)
{
    nextOp.HandleEndOfInput();
}