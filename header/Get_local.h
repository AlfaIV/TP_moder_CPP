// Get_local.h


#ifndef Get_local
#define Get_local

    #include <string>
    #include <vector> 
    #include <map>

    #include "Get_films.h"


    
    using namespace std;
    
    int getLocalNameOfFilm(vector<string> &parseString,
                        int i,
                        map <string, struct strFilm> &mp,
                        struct strInputData &inputData);

#endif