#include "bracket.hpp"

void    empty_bracket()
{
    std::cout << "Empty bracket MAP" << std::endl;
    std::map<int, int> map;
    //std::map<std::string, int>::iterator  it = map.begin();
   // std::cout << "first : " << it->first << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map[0] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
    std::cout << map[1] << std::endl;
    std::cout << map[2] << std::endl;
    std::cout << map[9] << std::endl;
    std::cout << map[4] << std::endl;
    std::cout << map[5] << std::endl;
    std::cout << map[6] << std::endl;
    std::cout << map[7] << std::endl;
    std::cout << map[8] << std::endl;
    std::cout << map[10] << std::endl;
    std::cout << map[11] << std::endl;
    std::cout << map[12] << std::endl;
    std::cout << "size : " << map.size() << std::endl;
    std::cout << map[5] << std::endl;
    std::cout << map[12] << std::endl;
    std::cout << "size : " << map.size() << std::endl;
    //std::cout << map["tes"] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
}

void    bracket_map()
{
    std::cout << "Bracket MAP" << std::endl;
    std::map<int, int> map;
    //std::map<std::string, int>::iterator  it = map.begin();
    // std::cout << "first : " << it->first << std::endl;
    // std::cout << "size : " << map.size() << std::endl;
    map[0] = 1;
    std::cout << map[0] << std::endl;
    // "size : " << map.size();
    map[1] = 2;
    std::cout << map[1] << std::endl;
    map[2] = 3;
    std::cout << map[2] << std::endl;
    map[9] = 4;
    std::cout << map[9] << std::endl;
    map[4] = 5;
    std::cout << map[4] << std::endl;
    map[5] = 6;
    std::cout << map[5] << std::endl;
    map[6] = 7;
    std::cout << map[6] << std::endl;
    map[7] = 8;
    std::cout << map[7] << std::endl;
    map[8] = 9;
    std::cout << map[8] << std::endl;
    map[10] = 10;
    std::cout << map[10] << std::endl;
    map[11] = 11;
    std::cout << map[11] << std::endl;
    map[12] = 12;
    std::cout << map[12] << std::endl;
    map[5] = 13;
    std::cout << map[5] << std::endl;
    map[12] = 14;
    std::cout << map[12] << std::endl;
    //std::cout << map["tes"] << std::endl;
   // std::cout << "size : " << map.size() << std::endl;
}