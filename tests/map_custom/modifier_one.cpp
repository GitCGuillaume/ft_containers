#include "modifier_one.hpp"

void    simple_clear_custom()
{
    std::cout << "simple clear CUSTOM" << std::endl;
    ft::map<int, int>   map;

    std::cout << "MAX SIZE : " << map.max_size() << std::endl;
    for (short int i = 0; i < 5000; i++)
        map[i] = i;
    std::cout << "Is empty ? : " << map.empty() << std::endl;
    map.clear();
    std::cout << "Is empty ? : " << map.empty() << std::endl;
    std::cout << "MAX SIZE : " << map.max_size() << std::endl;
}

void    simple_erase_custom()
{
    std::cout << "simple erase CUSTOM" << std::endl;
    ft::map<int, int>  map;

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

void    range_erase_custom()
{
    std::cout << "RANGE erase CUSTOM" << std::endl;
    ft::map<int, int>  map;

    for (int i = 1; i < 5; i++)
        map[i] = i;
    ft::map<int, int>::iterator    it = map.begin();
    ft::map<int, int>::iterator    it2 = map.begin();
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

void    erase_key_custom()
{
    std::cout << "erase KEY CUSTOM" << std::endl; 
    ft::map<std::string, int>  map;

    map["one"] = 1;
    map["two"] = 2;
    map["ten"] = 10;
    map["thousand"] = 10;
    map["fourty"] = 10;
    map["seventy"] = 10;
    std::cout << map.erase("zero") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("one") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("ten") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("two") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("three") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("thousand") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("fourty") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
    std::cout << map.erase("seventy") << std::endl;
    for (ft::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it : " << it->first << std::endl;
}

void    insert_value_type_custom()
{
    std::cout << "Insert value type" << std::endl;
    ft::map<int, int>  map;
    ft::pair<ft::map<int, int>::iterator, bool>   pair;

    pair = map.insert(ft::make_pair(10, 11));
    std::cout << "bool : " << pair.second << std::endl;
    pair = map.insert(ft::make_pair(10, 11));
    std::cout << "bool : " << pair.second << std::endl;
    map.insert(ft::make_pair(8, 10));
    map.insert(ft::make_pair(10000, 10));
    map.insert(ft::make_pair(1454, 14440));
    pair = map.insert(ft::make_pair(11, 10));
    std::cout << "bool : " << pair.second << std::endl;
    pair = map.insert(ft::make_pair(11, 11));
    std::cout << "bool : " << pair.second << std::endl;
    for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    insert_hint_custom()
{
    std::cout << "Insert hint CUSTOM" << std::endl;
    ft::map<int, int>  map;

    map.insert(ft::make_pair(10, 0));
    map.insert(ft::make_pair(0, 0));
    map.insert(ft::make_pair(-10, 0));
    map.insert(ft::make_pair(42254, 0));
    map.insert(ft::make_pair(42, 0));
    map.insert(ft::make_pair(21, 0));
    map.insert(map.find(42), ft::pair<int, int>(5, 123));
    map.insert(map.find(42), ft::pair<int, int>(43, 123));
    map.insert(map.find(42254), ft::pair<int, int>(44, 123));
    map.insert(map.find(0), ft::pair<int, int>(2147483647, 123));
    map.insert(map.find(21), ft::pair<int, int>(10, 124));
    map.insert(map.find(21), ft::pair<int, int>(42, 123));
    for (int i = 0; i < 50000; i++)
        map[i] = i;
    map.insert(map.end(), ft::pair<int, int>(-1000, 123));
    map.insert(map.begin(), ft::pair<int, int>(-2147483648, 123));
 //   for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
   //     std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    insert_range_custom()
{
    std::cout << "Insert Range CUSTOM" << std::endl;
    ft::map<double, int>   map;
    map[456546] = 54;
    map[546] = 54;
    map[-154] = 5648;
    map[1] = 1;
    for (int i = 1; i < 11; i++)
        map[i] = i;
    ft::map<double, int>   range;
    range.insert(map.begin(), map.end());
    for (ft::map<double, int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
    //for (int i = 1; i < 100000; i++)
   //     map[i] = i;
    range.insert(map.begin(), map.end());
}

void    map_swap_custom()
{
    std::cout << "MAP SWAP CUSTOM" << std::endl;
    ft::map<std::string, int>    map_1;
    ft::map<std::string, int>    map_2;

    map_1.swap(map_2);
    map_1.insert(ft::make_pair("one", 1));
    map_1.insert(ft::make_pair("hjfjhj", 6565));
    map_1.insert(ft::make_pair("gtgcfgfege", -45654));
    map_1.insert(ft::make_pair("42", 42));
    map_1.insert(ft::make_pair("rgrcgr", -78787));
    map_2.insert(ft::make_pair("gfxgd", 0));
    map_2.insert(ft::make_pair("trdrt", 1111));
    ft::map<std::string, int>::iterator it1 = map_1.begin();
    ft::map<std::string, int>::iterator it2 = map_2.begin();
    std::cout << "BEFORE" << std::endl;
    std::cout << "map_1 size : " << map_1.size() << std::endl;
    std::cout << "map_2 size : " << map_2.size() << std::endl;
    map_1.swap(map_2);
    std::cout << "AFTER" << std::endl;
    std::cout << "map_1 size : " << map_1.size() << std::endl;
    std::cout << "map_2 size : " << map_2.size() << std::endl;
    std::cout << "map_1" << std::endl;
    for  (ft::map<std::string, int>::const_iterator it = map_1.begin(); it != map_1.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << std::endl;    
    std::cout << "map_2" << std::endl;
    for  (ft::map<std::string, int>::const_iterator it = map_2.begin(); it != map_2.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << std::endl;    
    std::cout << "it_1 validity : " << (it1 == map_1.begin()) << std::endl;
    std::cout << "it_2 validity : " << (it2 == map_2.begin()) << std::endl;
}