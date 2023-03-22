// Get_year.h

#ifndef Get_year
#define Get_year

    // #include <fstream>
    // #include <sstream> 
    // #include <iostream> 
    #include <string>
    #include <vector> 
    #include <map>


    #include "Get_films.h"

    
    using namespace std;
    int _stoi(std::string str, int* p_value);
    bool years_check(std::vector<std::string> str, int year);

    int Get_data_with_year(vector<string> &parse_string,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &input_data);

                        // func(parse_string,i,films,input_data)
    // bool Cheak_data_with_year((vector<string>), map <string, _film_> &films);

#endif