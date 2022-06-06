#include "lookup.hpp"

static void    exist(std::map<int, int>::iterator it, std::map<int, int>& map)
{
    if (it == map.end())
        std::cout << "Does not exist" << std::endl;
    else
        std::cout << "Exist" << std::endl;
}

void    lookup_find()
{
    std::cout << "Map find" << std::endl;
    std::map<int, int>  map;
    std::map<int, int>::iterator    it;

    map.insert(std::make_pair(10, 0));
    map.insert(std::make_pair(0, 0));
    map.insert(std::make_pair(-10, 0));
    map.insert(std::make_pair(42254, 0));
    map.insert(std::make_pair(42, 0));
    map.insert(std::make_pair(21, 0));
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

void    map_count()
{
    std::cout << "COUNT" << std::endl;
    std::map<int, int>  map;
    map[1] = 1;
    map[1] = 0;
    map[0] = 1;
    std::map<int, int>  map2;
    std::cout << map.count(1) << std::endl;
    std::cout << map.count(0) << std::endl;
    std::cout << map.count(2) << std::endl;
    std::cout << map2.count(0) << std::endl;
}