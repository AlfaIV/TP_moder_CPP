// Get_year.cpp

#include "Get_year.h"



bool yearsCheck(std::vector<std::string> str,
                int year)
{
    int isAdult, _year;
    if (_stoi(str[4], &isAdult) == 0 && _stoi(str[5], &_year) == 0)
    {
        if (isAdult == 0 && _year == year){
            return true;
        };
    };
    return false;
}

int getDataWithYear(vector<string> &parseString,
                    int i,
                    map <string, struct _film_> &mp,
                    struct _input_data_ &inputData)
{
    // функция получения года выпуска фильма
    
    int year = inputData.year;

    // проверка корректности таблицы
    if (i == 0 ){
        // cout << parse_string[0] << " " << parse_string[2] << " " << parse_string[4] << endl;
        if (parseString[0] == "tconst" &&
            parseString[2] == "primaryTitle" &&
            parseString[4] == "isAdult")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << inputData.path_to_year << endl;
            return 1;
        }
    };

    // //cout << years_check(parse_string, year) << endl;
    if(yearsCheck(parseString, year) == 1)
    {
        pair<string, _film_> p = make_pair(parseString[0],_film_{parseString[0],parseString[2],-1});
        mp.insert(p);
    };
    return 0;
}