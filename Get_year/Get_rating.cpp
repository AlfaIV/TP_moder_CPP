// Get_rating.cpp

#include "Get_year.h"

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