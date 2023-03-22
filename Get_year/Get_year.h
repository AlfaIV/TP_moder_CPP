// Get_year.h

#ifndef Get_year
#define Get_year


    #include <string>
    #include <vector> 
    #include <map>


    #include "../Get_films.h"

    
    using namespace std;
    int _stoi(std::string str, int* p_value);
    bool years_check(std::vector<std::string> str, int year);

    int Get_data_with_year(vector<string> &parse_string,
                        int i,
                        map <string, struct _film_> &mp,
                        struct _input_data_ &input_data);

#endif