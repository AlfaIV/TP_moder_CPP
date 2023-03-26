// Sort_films.h

#ifndef Sort_films
#define Sort_films

    #include <string>
    #include <vector> 
    #include <map>

    #include "Get_films.h"


    
    using namespace std;

    bool compareTwoName(string const& lName,
                        string const& rName);

    bool compareTwoFilm(struct strFilm const& lFilm,
                        struct strFilm const& rFilm);

    void sortFilmToRating(map <string, struct strFilm> &mp);

#endif