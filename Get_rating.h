//  Get_rating.h

#ifndef Get_rating
#define Get_rating

    // #include <fstream>
    // #include <sstream> 
    // #include <iostream> 
    #include <string>
    #include <vector> 
    #include <map>


    #include "Get_films.h"

    
    using namespace std;
    int Get_rating_to_film(vector<string> &parse_string, int i, map <string, struct _film_> &mp, struct _input_data_ &input_data);
#endif