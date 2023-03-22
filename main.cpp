#include <iostream>
#include <fstream>
#include <string.h>
#include <vector> 
#include <sstream> 
#include <iostream> 
#include <map>

#include "Get_films.h"
// #include "Get_year.h"

using namespace std; 


// void Test_Read_str_from_file()
// {
//     //Read_str_from_file("data/example_data.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.basics.tsv", &Get_data_with_year);
//     Read_str_from_file("data/title.ratings.tsv", &Get_rating_to_film);
//     Read_str_from_file("data/title.akas.tsv", &Get_local_name_of_film);
//     // print_mp(mp);
//     Sort_film_to_rating();
// }


int main(int argc, char *argv[])
{
    Get_films(argc, argv);

}
