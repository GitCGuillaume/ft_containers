#include "bracket.hpp"

void    empty_bracket()
{
    std::cout << "Empty bracket MAP" << std::endl;
    std::map<std::string, int> map;

    std::cout << "size : " << map.size() << std::endl;
    std::cout << "map : " <<  map["test"] << std::endl;
    std::cout << "size : " << map.size() << std::endl;
    std::cout << map["test"] << std::endl;
    std::cout << map["tes"] << std::endl;
    std::cout << "size : " << map.size() << std::endl;
}