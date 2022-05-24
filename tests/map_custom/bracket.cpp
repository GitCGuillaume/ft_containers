#include "bracket.hpp"

void    empty_bracket_custom()
{
    std::cout << "Empty bracket MAP CUSTOM" << std::endl;
    ft::map<int, int> map;
    //ft::map<std::string, int>::iterator  it = map.begin();
   // std::cout << "first : " << it->first << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map[0] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map[1] << std::endl;
    std::cout << map[2] << std::endl;
    std::cout << map[3] << std::endl;
    std::cout << map[4] << std::endl;
    std::cout << map[5] << std::endl;
    //std::cout << map["tes"] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
}