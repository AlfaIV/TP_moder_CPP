#include <iostream>
#include <fstream>
#include <string.h>
#include <vector> 
#include <sstream> 
#include <iostream> 
#include <map>

#include "Get_Films/Get_films.h"

using namespace std; 

// map <string, _film_> mp;

// void print_mp(map <string, _film_> &mp)
// {
//     map <string, _film_> :: iterator it = mp.begin();
//     for (int i = 0; it != mp.end(); it++, i++) {  // выводим их
//         //cout << it->first << endl;
//         cout << it->second << endl;

//     };
// };

// bool years_check(std::vector<std::string> str, int year)
// {
//     int IsAdult, _Year;
//     if (_stoi(str[4], &IsAdult) == 0 && _stoi(str[5], &_Year) == 0)
//     {
//         if (IsAdult == 0 && _Year == year){
//             return true;
//         };
//     };
//     return false;
// }
 
// void Get_data_with_year(vector<string> parse_string, int i)
// {
//     int year = 1894;
//     if (i == 0){
//         //fix it
//         //нужно проверка структуры таблицы
//         //std::cout << "pass" << std::endl;
//         return;
//     };

//     //cout << years_check(parse_string, year) << endl;
//     if(years_check(parse_string, year) == 1)
//     {
//         pair<string, _film_> p = make_pair(parse_string[0],_film_{parse_string[0],parse_string[2],-1});
//         mp.insert(p);
//     };
// }


// void Get_rating_to_film(vector<string> parse_string, int i)
// {
//     int rating = 1e3;

//     if (i == 0){
//         //fix it
//         //нужно проверка структуры таблицы
//         //std::cout << "pass" << std::endl;
//         return;
//     };

//     //cout << years_check(parse_string, year) << endl;
//     map <string, _film_> :: iterator current_film;
//     current_film = mp.find(parse_string[0]);

//     if(current_film != mp.end())
//     {
//         int numVotes,rating;
//         if(_stoi(parse_string[2],&numVotes) == 0)
//         {
//             if (numVotes > 1e3 && _stoi(parse_string[1],&rating ) == 0)
//             {
//                 current_film->second.rating = rating;
//                 // cout << current_film->second.rating << endl;
//                 // cout << rating << endl;
//             }else
//             {
//                 mp.erase(current_film);  
//             }
//         };
//         // cout << 1 << endl;
//     };
// }

// void Get_local_name_of_film(vector<string> parse_string, int i)
// {
//     if (i == 0){
//         //fix it
//         //нужно проверка структуры таблицы
//         //std::cout << "pass" << std::endl;
//         return;
//     };

//     //cout << years_check(parse_string, year) << endl;
//     map <string, _film_> :: iterator current_film;
//     current_film = mp.find(parse_string[0]);

//     if(current_film != mp.end())
//     {
//         if(parse_string[3] == "RU")
//         {
//             // cout << parse_string[2] << endl;
//             current_film->second.local_name = parse_string[2];
//         };
//     };  
// }

// bool Compare_two_film(_film_ const& l_film, _film_ const& r_film)
// {
//     return l_film.rating < r_film.rating;
// };

// bool Compare_two_name(string const& l_name, string const& r_name)
// {
//     return Compare_two_film(mp.find(l_name)->second, mp.find(r_name)->second);
// };

// void Sort_film_to_rating()
// {
//     vector <string> ID_list;

//     for (map <string, _film_> :: iterator it = mp.begin(); it != mp.end(); it++) 
//     {
//         ID_list.push_back(it->first);
//     };


//     for (int i = 0; i < ID_list.size(); ++i) {
//         // cout << ID_list[i] << " ";
//         for (int j = 0; j < ID_list.size() - 1; ++j)
//         {
//             if (Compare_two_name(ID_list[j + 1],ID_list[j]))
//             {
//                 std:swap(ID_list[j + 1],ID_list[j]);
//             }
//         }
//     }

//     for (int i = 0; i < ID_list.size(); ++i) {
//         cout << mp.find(ID_list[i])->second << endl;
//     }
// }


// void Test_Read_str_from_file()
// {
//     //Read_str_from_file("data/example_data.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.basics.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.ratings.tsv", &Get_rating_to_film);
//     Read_str_from_file("data/title.akas.tsv", &Get_local_name_of_film);
//     // print_mp(mp);
//     Sort_film_to_rating();
// }


int main(int argc, char *argv[])
{
    Get_films(argc, argv);

}
