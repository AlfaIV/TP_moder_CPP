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

    struct strFilm
    {
        std::string id;
        std::string name;
        int rating;
        std::string local_name;
        friend std::ostream& operator<< (std::ostream& stream, const strFilm& film) {
            // stream << "id: " << film.id << ", name: " << film.name << ", local_name: " << film.local_name <<  ", rating: " << film.rating  << std::endl;
            stream << "Название фильма: " << film.local_name <<  ", Рейтинг: " << film.rating  << std::endl;
            return stream;
        }
    };

    struct strInputData_
    {
        int year = 0;
        std::string pathToYear;
        std::string pathToRating;
        std::string pathToName;

        friend std::ostream& operator<< (std::ostream& stream, const strInputData_& input_data) {
            stream << "year: " << input_data.year <<  ", path_to_year: " << input_data.pathToYear << "path_to_rating: " << input_data.pathToRating <<  ", path_to_name: " << input_data.pathToName  << std::endl;
            return stream;
        }

        inline bool valid() const
        {
            return !pathToYear.empty() && !pathToRating.empty() && !pathToName.empty() && year != 0;
        }
    };


    int getFilms(int argc,
                char *argv[]);

    bool getPath(int argc,
                char *argv[],
                struct strInputData_ &input_data);

    void tokenize(std::string const &str,
                    const char delim,
                    std::vector<std::string> &out);
    
    int _stoi(std::string str,
                int* pValue);

    int readStrFromFile(string path, 
                        std::function<int (vector<string> &, int i, map <string, struct strFilm> &, struct strInputData_ &)> func,
                        map <string, strFilm> &films,
                        struct strInputData_ &inputData);

    void printMap(map <string,
                struct strFilm> &mp);
                
#endif