#include "bracket.hpp"

void    empty_bracket_custom()
{
    std::cout << "Empty bracket MAP CUSTOM" << std::endl;
    ft::map<std::string, int> map;
    //ft::map<std::string, int>::iterator  it = map.begin();
   // std::cout << "first : " << it->first << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map["test"] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map["u"] << std::endl;
    std::cout << map["b"] << std::endl;
    std::cout << map["a"] << std::endl;
    std::cout << map["z"] << std::endl;
    //std::cout << map["tes"] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
}