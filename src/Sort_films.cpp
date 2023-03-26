// Sort_films.cpp

#include "Sort_films.h"

// 
// функции для реалитзации сравнений по назвнию на основе рейтинга

bool compareTwoFilm(struct strFilm const& lFilm,
                    struct strFilm const& rFilm)
{
    return lFilm.rating < rFilm.rating;
};

bool compareTwoName(string const& lName,
                    string const& rName, 
                    map <string, struct strFilm> &mp)
{
    return compareTwoFilm(mp.find(lName)->second, mp.find(rName)->second);
};

void sortFilmToRating(map <string, struct strFilm> &mp)
{
    // функция которая преобразует словарь, с отобранными фильмами,
    // в отсортированный по рейтингу вектор
    // и вывод его(вектор)
    vector<string> idList;

    for (map <string, strFilm> :: iterator it = mp.begin(); it != mp.end(); it++) 
    {
        idList.push_back(it->first);
    };


    for (int i = 0; i < idList.size(); ++i) {
        // cout << idList[i] << " ";
        for (int j = 0; j < idList.size() - 1; ++j)
        {
            if (compareTwoName(idList[j],idList[j + 1], mp))
            {
                std:swap(idList[j],idList[j + 1]);
            }
        }
    }

    for (int i = 0; i < idList.size(); ++i) {
        cout << mp.find(idList[i])->second << endl;
    }
}