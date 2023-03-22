// Get_year.cpp

#include "Get_year.h"



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

int Get_data_with_year(vector<string> &parse_string,
                    int i,
                    map <string, struct _film_> &mp,
                    struct _input_data_ &input_data)
{
    int year = input_data.year;
    if (i == 0 ){
        // cout << parse_string[0] << " " << parse_string[2] << " " << parse_string[4] << endl;
        if (parse_string[0] == "tconst" && parse_string[2] == "primaryTitle" && parse_string[4] == "isAdult")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << input_data.path_to_year << endl;
            return 1;
        }
    };

    // //cout << years_check(parse_string, year) << endl;
    if(years_check(parse_string, year) == 1)
    {
        pair<string, _film_> p = make_pair(parse_string[0],_film_{parse_string[0],parse_string[2],-1});
        mp.insert(p);
    };
    return 0;
}