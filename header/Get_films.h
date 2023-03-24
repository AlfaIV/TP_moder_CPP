#ifndef GET_FILMS
#define GET_FILMS

    #include <fstream>
    #include <sstream> 
    #include <functional>
    #include <iostream> 
    #include <string.h>
    #include <vector> 
    #include <map>
    
    #include "Get_year.h"
    #include "Get_rating.h"
    #include "Get_local.h"
    #include "Sort_films.h"
    
    using namespace std;

    struct _film_
    {
        std::string id;
        std::string name;
        int rating;
        std::string local_name;
        friend std::ostream& operator<< (std::ostream& stream, const _film_& film) {
            // stream << "id: " << film.id << ", name: " << film.name << ", local_name: " << film.local_name <<  ", rating: " << film.rating  << std::endl;
            stream << "Название фильма: " << film.local_name <<  ", Рейтинг: " << film.rating  << std::endl;
            return stream;
        }
    };

    struct _input_data_
    {
        int year = 0;
        std::string path_to_year;
        std::string path_to_rating;
        std::string path_to_name;

        friend std::ostream& operator<< (std::ostream& stream, const _input_data_& input_data) {
            stream << "year: " << input_data.year <<  ", path_to_year: " << input_data.path_to_year << "path_to_rating: " << input_data.path_to_rating <<  ", path_to_name: " << input_data.path_to_name  << std::endl;
            return stream;
        }

        inline bool valid() const
        {
            return !path_to_year.empty() && !path_to_rating.empty() && !path_to_name.empty() && year != 0;
        }
    };


    int getFilms(int argc, char *argv[]);

    bool getPath(int argc, char *argv[], struct _input_data_ &input_data);

    void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out);
    
    int _stoi(std::string str, int* p_value);

    int readStrFromFile(string path, 
                            std::function<int (vector<string> &, int i, map <string, struct _film_> &, struct _input_data_ &)> func,
                            map <string, _film_> &films,
                            struct _input_data_ &input_data);

    void printMap(map <string, struct _film_> &mp);
#endif