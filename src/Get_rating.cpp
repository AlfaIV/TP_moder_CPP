// Get_rating.cpp

#include "Get_rating.h"

int getRatingToFilm(vector<string> &parseString,
                    int i,
                    map <string,
                    struct strFilm> &mp,
                    struct strInputData &inputData)
{
    // считывание рейтинга фильма
    // 
    int rating = 1e3;


    // 
    // проверка корректности таблиц
    if (i == 0 ){
        // cout << parseString[0] << " " << parseString[1] << " " << parseString[2] << endl;
        if (parseString[0] == "tconst" &&
            parseString[1] == "averageRating" &&
            parseString[2] == "numVotes")
        {
            return 0;
        }else{
            cout << "No corect data in path: " << inputData.pathToRating << endl;
            return 1;
        }
    };

    //cout << years_check(parseString, year) << endl;
    map <string, strFilm> :: iterator currentFilm;
    currentFilm = mp.find(parseString[0]);

    if(currentFilm != mp.end())
    {
        int numVotes,rating;
        if(modStoi(parseString[2],&numVotes) == 0)
        {
            if (numVotes > 1e3 && 
                modStoi(parseString[1],&rating ) == 0)
            {
                currentFilm->second.rating = rating;
                // cout << currentFilm->second.rating << endl;
                // cout << rating << endl;
            }else
            {
                mp.erase(currentFilm);  
            }
        };
    };
    return 0;
}