// Get_year.h

#ifndef Get_year
#define Get_year

    #include <string>
    #include <vector> 
    #include <map>

    #include "Get_films.h"
    

    
    using namespace std;

    bool yearsCheck(std::vector<std::string> str, int year);

    int getDataWithYear(vector<string> &parseString,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &inputData);

#endif