// Get_local.h


#ifndef Get_local
#define Get_local

    #include <string>
    #include <vector> 
    #include <map>


    #include "../Get_films/Get_films.h"

    
    using namespace std;
    
    int Get_local_name_of_film(vector<string> &parse_string,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &input_data);

#endif