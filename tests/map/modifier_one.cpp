#include "modifier_one.hpp"

void    simple_clear()
{
    std::cout << "simple clear CUSTOM" << std::endl;
    std::map<int, int>   map;

    for (short int i = 0; i < 5000; i++)
        map[i] = i;
    map.clear();
}

void    simple_erase()
{
    std::cout << "simple erase" << std::endl;
    std::map<int, int>  map;

    for (int i = 0; i < 3; i++)
        map[i] = i;
    for (int i = 0; i < 3; i++)
    {
        std::cout  << "first before erase(pos) : " << map.begin()->first << std::endl;
        map.erase(map.begin());
        if (i != 2)
            std::cout  << "first after erase(pos) : " << map.begin()->first << std::endl;
    }
}

void    range_erase()
{
    std::cout << "RANGE erase" << std::endl;
    std::map<int, int>  map;

    for (int i = 1; i < 5; i++)
        map[i] = i;
    std::map<int, int>::iterator    it = map.begin();
    std::map<int, int>::iterator    it2 = map.begin();
    it++;
    it2++;
    it2++;
    map.erase(it, it2);
    it = map.begin();
    for (int i = 0; i < 2; i++, it++)
         std::cout  << "first value erase(first, last) : " << it->first << std::endl;
    it = map.begin();
    map.erase(it, map.end());
    //std::cout  << "first value erase(first, last) : " << it->first << std::endl;
}

void    erase_key()
{
    std::cout << "erase KEY" << std::endl; 
    std::map<std::string, int>  map;

    map["one"] = 1;
    map["two"] = 2;
    std::cout << map.erase("zero") << std::endl;;
    std::cout << map.erase("one") << std::endl;;
    std::cout << map.erase("two") << std::endl;;
    std::cout << map.erase("three") << std::endl;;
}