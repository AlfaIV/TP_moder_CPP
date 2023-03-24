// Get_rating.cpp

#include "Get_rating.h"

int getRatingToFilm(vector<string> &parse_string, int i, map <string, struct _film_> &mp, struct _input_data_ &input_data)
{
    // считывание рейтинга фильма
    // 
    int rating = 1e3;


    // 
    // проверка корректности таблиц
    if (i == 0 ){
        // cout << parse_string[0] << " " << parse_string[1] << " " << parse_string[2] << endl;
        if (parse_string[0] == "tconst" && parse_string[1] == "averageRating" && parse_string[2] == "numVotes")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << input_data.path_to_rating << endl;
            return 1;
        }
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
                // cout << 2 << endl;
                current_film->second.rating = rating;
                // cout << current_film->second.rating << endl;
                // cout << rating << endl;
            }else
            {
                mp.erase(current_film);  
            }
        };
    };
    return 0;
}