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
    string local_name;
    friend std::ostream& operator<< (std::ostream& stream, const _film_& film) {
        // stream << "id: " << film.id << ", name: " << film.name << ", local_name: " << film.local_name <<  ", rating: " << film.rating  << std::endl;
        stream << "Название фильма: " << film.local_name <<  ", Рейтинг: " << film.rating  << std::endl;
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


void Get_rating_to_film(vector<string> parse_string, int i)
{
    int rating = 1e3;

    if (i == 0){
        //fix it
        //нужно проверка структуры таблицы
        //std::cout << "pass" << std::endl;
        return;
    };

    //cout << years_check(parse_string, year) << endl;
    map <string, _film_> :: iterator current_film;
    current_film = mp.find(parse_string[0]);

    if(current_film != mp.end())
    {
        int numVotes,rating;
        if(_stoi(parse_string[2],&numVotes) == 0)
        {
            if (numVotes > 1e3 && _stoi(parse_string[1],&rating ) == 0)
            {
                current_film->second.rating = rating;
                // cout << current_film->second.rating << endl;
                // cout << rating << endl;
            }else
            {
                mp.erase(current_film);  
            }
        };
        // cout << 1 << endl;
    };
}

void Get_local_name_of_film(vector<string> parse_string, int i)
{
    if (i == 0){
        //fix it
        //нужно проверка структуры таблицы
        //std::cout << "pass" << std::endl;
        return;
    };

    //cout << years_check(parse_string, year) << endl;
    map <string, _film_> :: iterator current_film;
    current_film = mp.find(parse_string[0]);

    if(current_film != mp.end())
    {
        if(parse_string[3] == "RU")
        {
            // cout << parse_string[2] << endl;
            current_film->second.local_name = parse_string[2];
        };
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

bool Compare_two_film(_film_ const& l_film, _film_ const& r_film)
{
    return l_film.rating < r_film.rating;
};

bool Compare_two_name(string const& l_name, string const& r_name)
{
    return Compare_two_film(mp.find(l_name)->second, mp.find(r_name)->second);
};

void Sort_film_to_rating()
{
    vector <string> ID_list;

    for (map <string, _film_> :: iterator it = mp.begin(); it != mp.end(); it++) 
    {
        ID_list.push_back(it->first);
    };


    for (int i = 0; i < ID_list.size(); ++i) {
        // cout << ID_list[i] << " ";
        for (int j = 0; j < ID_list.size() - 1; ++j)
        {
            if (Compare_two_name(ID_list[j + 1],ID_list[j]))
            {
                std:swap(ID_list[j + 1],ID_list[j]);
            }
        }
    }

    for (int i = 0; i < ID_list.size(); ++i) {
        cout << mp.find(ID_list[i])->second << endl;
    }
}


// void Test_Read_str_from_file()
// {
//     // Read_str_from_file("data/example_data.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.basics.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.ratings.tsv", &Get_rating_to_film);
//     Read_str_from_file("data/title.akas.tsv", &Get_local_name_of_film);
//     // print_mp(mp);
//     Sort_film_to_rating();
// }

void Get_path(int argc, char *argv[])
{
    //добавить передачу года поиска фильма
    string path_to_name, path_to_rating, path_to_year;
    if(argc == 5)
    {
        path_to_year = argv[1];
        path_to_rating = argv[2];
        path_to_name = argv[3];
    }

    // if(argc == 3*2+1)
    // {
    //     while(int i = 1; i < argc; ++i)
    //     {
    //         switch ( argv[i] ) {
    //             case "":
    //                 // Code
    //                 break;
    //             case c:
    //                 // Code
    //                 break;
    //             default:
    //                 // Code
    //                 break;
    //     }
    // }

    // cout << "path_to_year: " << path_to_year << endl;
    // cout << "path_to_rating: " << path_to_rating << endl;
    // cout << "path_to_name: " << path_to_name << endl;

    Read_str_from_file(path_to_year, &Get_data_with_year);
    Read_str_from_file(path_to_rating, &Get_rating_to_film);
    Read_str_from_file(path_to_name, &Get_local_name_of_film);
    // print_mp(mp);
    Sort_film_to_rating();

}

int main(int argc, char *argv[])
{
    //Test_Read_str_from_file();
    Get_path(argc, argv);
}
