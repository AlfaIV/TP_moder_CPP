#include <iostream>
#include <fstream>
#include <string.h>
#include <string> 
#include <vector> 
#include <sstream> 
#include <iostream> 
#include <map>

using namespace std; 

struct _film_
{
    string id;
    string name;
    int rating;
    friend std::ostream& operator<< (std::ostream& stream, const _film_& film) {
        stream << "id: " << film.id << ", name: " << film.name <<  ", rating: " << film.rating  << std::endl;
        return stream;
    }
};


map <string, _film_> mp;

void print_mp(map <string, _film_> &mp)
{
    map <string, _film_> :: iterator it = mp.begin();
    for (int i = 0; it != mp.end(); it++, i++) {  // выводим их
        //cout << it->first << endl;
        cout << it->second << endl;

    };
};

int _stoi(std::string str, int* p_value) {
    // wrapping std::stoi because it may throw an exception

    try {
        *p_value = std::stoi(str);
        return 0;
    }

    catch (const std::invalid_argument& ia) {
        //std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return -1;
    }

    catch (const std::out_of_range& oor) {
        //std::cerr << "Out of Range error: " << oor.what() << std::endl;
        return -2;
    }

    catch (const std::exception& e)
    {
        //std::cerr << "Undefined error: " << e.what() << std::endl;
        return -3;
    }
}

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
    int IsAdult, _Year;
    if (_stoi(str[4], &IsAdult) == 0 && _stoi(str[5], &_Year) == 0)
    {
        if (IsAdult == 0 && _Year == year){
            return true;
        };
    };
    return false;
}
 
void Get_data_with_year(vector<string> parse_string, int i)
{
    int year = 1894;
    if (i == 0){
        //fix it
        //нужно проверка структуры таблицы
        //std::cout << "pass" << std::endl;
        return;
    };

    //cout << years_check(parse_string, year) << endl;
    if(years_check(parse_string, year) == 1)
    {
        pair<string, _film_> p = make_pair(parse_string[0],_film_{parse_string[0],parse_string[2],-1});
        mp.insert(p);
    };
}

void Read_str_from_file(string path, void (*func)(vector<string>, int))
{

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
                    func(parse_string, i);func(parse_string, i);
                    ++i;
                };
                func(parse_string, i);
                
            };
        };
    };
    in.close();     // закрываем файл
    
    //std::cout << "End of file" << std::endl;
};

void Test_Read_str_from_file()
{
    Read_str_from_file("data/example_data.tsv", &Get_data_with_year);
    // Read_str_from_file("data/title.basics.tsv");
    print_mp(mp);
}

int main()
{
    Test_Read_str_from_file();
}
