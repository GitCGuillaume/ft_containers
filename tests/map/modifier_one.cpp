#include "modifier_one.hpp"

void    simple_clear()
{
    std::cout << "simple clear CUSTOM" << std::endl;
    std::map<int, int>   map;

    std::cout << "MAX SIZE : " << map.max_size() << std::endl;
    for (short int i = 0; i < 5000; i++)
        map[i] = i;
    std::cout << "Is empty ? : " << map.empty() << std::endl;
    map.clear();
    std::cout << "Is empty ? : " << map.empty() << std::endl;
    std::cout << "MAX SIZE : " << map.max_size() << std::endl;
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
    std::map<std::string, int>  map;

    map["one"] = 1;
    map["two"] = 2;
    map["ten"] = 10;
    map["thousand"] = 10;
    map["fourty"] = 10;
    map["seventy"] = 10;
    std::cout << map.erase("zero") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("one") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("ten") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("two") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("three") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("thousand") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("fourty") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("seventy") << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
}

void    insert_value_type()
{
    std::cout << "Insert value type" << std::endl;
    std::map<int, int>  map;
    std::pair<std::map<int, int>::iterator, bool>   pair;

    pair = map.insert(std::make_pair(10, 11));
    std::cout << "bool : " << pair.second << std::endl;
    pair = map.insert(std::make_pair(10, 11));
    std::cout << "bool : " << pair.second << std::endl;
    map.insert(std::make_pair(8, 10));
    map.insert(std::make_pair(10000, 10));
    map.insert(std::make_pair(1454, 14440));
    pair = map.insert(std::make_pair(11, 10));
    std::cout << "bool : " << pair.second << std::endl;
    pair = map.insert(std::make_pair(11, 11));
    std::cout << "bool : " << pair.second << std::endl;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    insert_hint()
{
    std::cout << "Insert hint" << std::endl;
    std::map<int, int>  map;

    map.insert(std::make_pair(10, 0));
    map.insert(std::make_pair(0, 0));
    map.insert(std::make_pair(-10, 0));
    map.insert(std::make_pair(42254, 0));
    map.insert(std::make_pair(42, 0));
    map.insert(std::make_pair(21, 0));
    map.insert(map.find(42), std::pair<int, int>(5, 123));
    map.insert(map.find(42), std::pair<int, int>(43, 123));
    map.insert(map.find(42254), std::pair<int, int>(44, 123));
    map.insert(map.find(0), std::pair<int, int>(2147483647, 123));
    map.insert(map.find(21), std::pair<int, int>(10, 124));
    map.insert(map.find(21), std::pair<int, int>(42, 123));
    for (int i = 0; i < 50000; i++)
        map[i] = i;
    map.insert(map.end(), std::pair<int, int>(-1000, 123));
    map.insert(map.begin(), std::pair<int, int>(-2147483648, 123));
   // for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
     //   std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    insert_range()
{
    std::cout << "Insert Range" << std::endl;
    std::map<double, int>   map;
    map[456546] = 54;
    map[546] = 54;
    map[-154] = 5648;
    map[1] = 1;
    for (int i = 1; i < 11; i++)
        map[i] = i;
    std::map<double, int>   range;
    range.insert(map.begin(), map.end());
    for (std::map<double, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
    //for (int i = 1; i < 100000; i++)
    //    map[i] = i;
    range.insert(map.begin(), map.end());
}