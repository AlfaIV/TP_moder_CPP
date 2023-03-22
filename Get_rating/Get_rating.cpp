// Get_rating.cpp

#include "Get_rating.h"

// std::function<int (vector<string> &, int i, map <string, struct _film_> &mp, struct _input_data_ &input_data)> func,

int Get_rating_to_film(vector<string> &parse_string, int i, map <string, struct _film_> &mp, struct _input_data_ &input_data)
{
    int rating = 1e3;

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
            // cout << 1 << endl;
            if (numVotes > 1e3 && _stoi(parse_string[1],&rating ) == 0)
            {
                // cout << 2 << endl;
                current_film->second.rating = rating;
                // cout << current_film->second.rating << endl;
                // cout << rating << endl;
            }else
            {
                // cout << 3 << endl;
                mp.erase(current_film);  
            }
            // cout << 4 << endl;
        };
        // cout << 1 << endl;
    };
    // print_mp(mp);
    return 0;
}