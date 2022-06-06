#include "lookup.hpp"

static void    exist(ft::map<int, int>::iterator it, ft::map<int, int>& map)
{
    if (it == map.end())
        std::cout << "Does not exist" << std::endl;
    else
        std::cout << "Exist" << std::endl;
}

void    lookup_find_custom()
{
    std::cout << "Map find CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator    it;

    map.insert(ft::make_pair(10, 0));
    map.insert(ft::make_pair(0, 0));
    map.insert(ft::make_pair(-10, 0));
    map.insert(ft::make_pair(42254, 0));
    map.insert(ft::make_pair(42, 0));
    map.insert(ft::make_pair(21, 0));
    exist(map.find(0), map);
    exist(map.find(-1), map);
    exist(map.find(42254), map);
    exist(map.find(21), map);
    exist(map.find(21), map);
    exist(map.find(10), map);
    exist(map.find(-10), map);
    exist(map.find(-11), map);
    exist(map.find(46546456), map);
}