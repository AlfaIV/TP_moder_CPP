//  Get_rating.h

#ifndef Get_rating
#define Get_rating

    #include <string>
    #include <vector> 
    #include <map>


    #include "Get_films.h"



    using namespace std;
    
    int getRatingToFilm(vector<string> &parseString,
                        int i,
                        map <string,
                        struct strFilm> &mp,
                        struct strInputData &inputData);
#endif