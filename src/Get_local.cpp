// Get_local.cpp

#include "Get_local.h"

int getLocalNameOfFilm(vector<string> &parseString,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &inputData)
{
    // функция поиска российского названия фильма


    // проверка корректности таблицы
    if (i == 0 ){
        // cout << parseString[0] << " " << parseString[1] << " " << parseString[2] << endl;
        if (parseString[0] == "titleId" &&
            parseString[3] == "region" &&
            parseString[2] == "title")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << inputData.path_to_name << endl;
            return 1;
        }
    };

    //cout << years_check(parseString, year) << endl;
    map <string, _film_> :: iterator currentFilm;
    currentFilm = mp.find(parseString[0]);

    if(currentFilm != mp.end())
    {
        if(parseString[3] == "RU")
        {
            // cout << parseString[2] << endl;
            currentFilm->second.local_name = parseString[2];
        };
    };  
    return 0;
}