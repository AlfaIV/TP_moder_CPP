#include <iostream>
#include <fstream>
#include <string.h>
#include <vector> 
#include <sstream> 
#include <iostream> 
#include <map>

#include "Get_films.h"
// #include "Get_year.h"

using namespace std; 

// map <string, _film_> mp;

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
