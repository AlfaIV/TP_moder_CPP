#include <iostream>
#include <fstream>
#include <string.h>
#include <string> 
#include <vector> 
#include <sstream> 
#include <iostream> 

using namespace std; 

vector<string> parse_string(string str) { 
    string w; 
    istringstream iss(str); 
    vector<string> v; 
    while (iss >> w) v.push_back(w); 
    // cout << "array:\n"; 
    // for (int c = 0; c < v.size(); ++c) cout << v[c] << endl; 
    return v;
} 

void Test_parse_string(string str)
{
    vector<string> v; 
    //string str;
    //getline(std::cin,str);
    v = parse_string(str);
    for (int c = 0; c < v.size(); ++c) cout << v[c] << endl; 
}

void Read_str_from_file(sring path)
{
    string line;
 
    ifstream in(path); // окрываем файл для чтения
    if (in.is_open())
    {
        // getline(in, line);
        // std::cout << line << std::endl;
        // if (in.is_open())
        // {
        //     while (getline(in, line))
        //     {
        //         std::cout << line << std::endl;
        //     }
        // }
        for (int i = 0; i < 10; i++)
        {
            getline(in, line);
            cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл
     
    std::cout << "End of file" << std::endl;
}

void Test_Read_str_from_file()
{
    Read_str_from_file("data/example.tsv");
}

int main()
{
    //Test_parse_string("DSAFAJHDSKJASGD FDSGF SD       FDSJKGH   SDFJKGHJKSDF ");
    Test_Read_str_from_file();
}
