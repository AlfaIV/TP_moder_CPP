#include "Get_films.h"

int _stoi(std::string str, int* p_value) {
    //безопасная обертка над stoi
    try {
        *p_value = std::stoi(str);
        return 0;
    }

    catch (const std::invalid_argument& ia) {
        //std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return -1;
    }

    catch (const std::out_of_range& oor) {
        //std::cerr << "Out of Range error: " << oor.what() << std::endl;
        return -2;
    }

    catch (const std::exception& e)
    {
        //std::cerr << "Undefined error: " << e.what() << std::endl;
        return -3;
    }
}

void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    // парсинг строки на слова
    std::stringstream ss(str);
 
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}

int readStrFromFile(string path, 
                        std::function<int (vector<string> &, int i, map <string, struct _film_> &, struct _input_data_ &)> func,
                        map <string, _film_> &films,
                        struct _input_data_ &input_data)
{
    // функция, которая считывает файл и строку разбитую на слова передает в функцию
    string line;
 
    ifstream in(path); // окрываем файл для чтения
    if (in.is_open())
    {
        // getline(in, line);
        //std::cout << line << std::endl;
        if (in.is_open())
        {
            int i = 0;
            //проверка корректоности данных таблицы

            while (getline(in, line))
            {
                //std::cout << line << std::endl;

                vector<string> parse_string;
                tokenize(line,'\t',parse_string);

                // for (int c = 0; c < parse_string.size(); ++c) cout << parse_string[c] << endl;
                // cout << std::endl;

                if(func(parse_string,i,films,input_data) != 0)
                {
                    return 1;
                };
                if(i == 0){
                    i += 1;   
                }
                
            };
        };
    };
    in.close();     // закрываем файл
    
    //std::cout << "End of file" << std::endl;
    return 0;
};

bool getPath(int argc, char *argv[], struct _input_data_ &input_data)
{
    //обработка ввода из CLI

    std::string current_exec_name = argv[0]; // Name of the current exec program
    std::vector<std::string> all_args;

    if (argc > 1) {
        all_args.assign(argv + 1, argv + argc);
    }

    // cout << all_args[0] << endl;
    // cout << all_args[0+1] << endl;

    int len_of_input_data = 8;
    if (all_args.size() == len_of_input_data) {  
        for (int i = 0; i < len_of_input_data; ++i)
        {
            // cout << all_args[i] << endl;    
            if (all_args[i] == "-find_year"){
                if(_stoi(all_args[i + 1],&input_data.year) != 0)
                {
                    return false;
                }
                //input_data.year = _stoi(all_args[i]);
            }else if(all_args[i] == "-path_to_year"){
                input_data.path_to_year = all_args[i + 1];
            }else if(all_args[i] == "-path_to_rating"){
                input_data.path_to_rating = all_args[i + 1];
            }else if(all_args[i] == "-path_to_name"){
                input_data.path_to_name = all_args[i + 1];
            }
        }
    }
    // std::cout << input_data << endl;
    return true;
}

void printMap(map <string, struct _film_> &mp)
{
    map <string, struct _film_> :: iterator it = mp.begin();
    for (int i = 0; it != mp.end(); it++, i++) {
        //cout << it->first << endl;
        cout << it->second << endl;

    };
};

int getFilms(int argc, char *argv[])
{
    // основная функция обработчик, находиться в main
    struct _input_data_ input_data;
    getPath(argc, argv, input_data);
    if (input_data.valid() != true)
    {
        cout << "No current input, please retry" << endl;
        return 1;
    }
    // std::cout << input_data << endl;

    map <string, _film_> films;

    // блок обработки первого файла с именами фильмов и годами
    if(readStrFromFile(input_data.path_to_year, &getDataWithYear, films, input_data) == 1)
    {
        cout << "Error" << endl;
        return 1;
    };
    // соответсвенно обработка файла с рейтингами фильмов
    if(readStrFromFile(input_data.path_to_rating, &getRatingToFilm, films, input_data))
    {
        cout << "Error" << endl;
        return 1;
    };
    // поиск русского названия фильма
    // 
    if(readStrFromFile(input_data.path_to_name, &getLocalNameOfFilm, films, input_data))
    {
        cout << "Error" << endl;
        return 1;
    };

    // print_mp(films);
    // 
    // вывод и сортировка словаря с фильмами
    sortFilmToRating(films);
    return 0;
}