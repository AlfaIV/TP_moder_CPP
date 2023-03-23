// Sort_films.cpp

#include "Sort_films.h"

// 
// функции для реалитзации сравнений по назвнию на основе рейтинга

bool Compare_two_film(struct _film_ const& l_film, struct _film_ const& r_film)
{
    return l_film.rating < r_film.rating;
};

bool Compare_two_name(string const& l_name, string const& r_name,  map <string, struct _film_> &mp)
{
    return Compare_two_film(mp.find(l_name)->second, mp.find(r_name)->second);
};

void Sort_film_to_rating(map <string, struct _film_> &mp)
{
    // функция которая преобразует словарь, с отобранными фильмами,
    // в отсортированный по рейтингу вектор
    // и вывод его(вектор)
    vector <string> ID_list;

    for (map <string, _film_> :: iterator it = mp.begin(); it != mp.end(); it++) 
    {
        ID_list.push_back(it->first);
    };


    for (int i = 0; i < ID_list.size(); ++i) {
        // cout << ID_list[i] << " ";
        for (int j = 0; j < ID_list.size() - 1; ++j)
        {
            if (Compare_two_name(ID_list[j],ID_list[j + 1], mp))
            {
                std:swap(ID_list[j],ID_list[j + 1]);
            }
        }
    }

    for (int i = 0; i < ID_list.size(); ++i) {
        cout << mp.find(ID_list[i])->second << endl;
    }
}