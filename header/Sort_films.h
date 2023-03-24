// Sort_films.h

#ifndef Sort_films
#define Sort_films

    #include <string>
    #include <vector> 
    #include <map>


    #include "Get_films.h"

    
    using namespace std;

    bool Compare_two_name(string const& l_name, string const& r_name);
    bool Compare_two_film(struct _film_ const& l_film, struct _film_ const& r_film);

    void Sort_film_to_rating(map <string, struct _film_> &mp);

#endif