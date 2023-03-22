// Get_local.cpp

#include "Get_local.h"

int Get_local_name_of_film(vector<string> &parse_string,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &input_data)
{
    if (i == 0 ){
        // cout << parse_string[0] << " " << parse_string[1] << " " << parse_string[2] << endl;
        if (parse_string[0] == "titleId" && parse_string[3] == "region" && parse_string[2] == "title")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << input_data.path_to_name << endl;
            return 1;
        }
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
    return 0;
}