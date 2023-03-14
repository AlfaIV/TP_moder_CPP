#include <iostream>
#include <fstream>
#include <string.h>
#include <string> 
#include <vector> 
#include <sstream> 
#include <iostream> 
#include <map>

using namespace std; 

void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    // строим поток из строки
    std::stringstream ss(str);
 
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}

bool years_check(std::vector<std::string> str, int year)
{
    // int IsAdult = std::stoi(str[4]);
    // cout << str[4] << endl;

    if (std::stoi(str[4]) == 0 && std::stoi(str[5]) == year){
        return true;
    }
    return false;
}
 

void Read_str_from_file(string path)
{
    int year = 1894;

    string line;
 
    ifstream in(path); // окрываем файл для чтения
    if (in.is_open())
    {
        getline(in, line);
        //std::cout << line << std::endl;
        if (in.is_open())
        {
            int i = 0;
            while (getline(in, line))
            {
                //std::cout << line << std::endl;

                vector<string> parse_string;
                tokenize(line,'\t',parse_string);

                // for (int c = 0; c < parse_string.size(); ++c) cout << parse_string[c] << endl;
                // cout << std::endl;
                
                if (i == 0){
                    //fix it
                    //нужно проверка структуры таблицы
                    //std::cout << "pass" << std::endl;
                    ++i;
                    continue;
                };

                //cout << years_check(parse_string, year) << endl;
                if(cout << years_check(parse_string, year))
                {

                };
            };
        };
    };
    in.close();     // закрываем файл
     
    //std::cout << "End of file" << std::endl;
};

void Test_Read_str_from_file()
{
    Read_str_from_file("data/example_data.tsv");
}

int main()
{
    Test_Read_str_from_file();
}
