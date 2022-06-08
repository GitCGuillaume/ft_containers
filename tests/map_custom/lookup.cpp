#include "lookup.hpp"

static void    exist(ft::map<int, int>::const_iterator it, ft::map<int, int>& map)
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

void    map_count_custom()
{
    std::cout << "COUNT CUSTOM" << std::endl;
    ft::map<int, int>  map;
    map[1] = 1;
    map[1] = 0;
    map[0] = 1;
    ft::map<int, int>  map2;
    std::cout << map.count(1) << std::endl;
    std::cout << map.count(0) << std::endl;
    std::cout << map.count(2) << std::endl;
    std::cout << map2.count(0) << std::endl;
}

void    map_equal_range_custom()
{
    std::cout << "Map Equal Range CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> range_iterator;

    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    map.insert(ft::make_pair(123, 123));
    map.insert(ft::make_pair(42, 42));
    map.insert(ft::make_pair(4554, -1));
    range_iterator = map.equal_range(42);
    for (ft::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (5)" << std::endl;
    range_iterator = map.equal_range(5);
	std::cout << "it->first : " << range_iterator.first->first << std::endl;
    std::cout << "it->first : " << range_iterator.second->first << std::endl;
    std::cout << "New equal_range call (123)" << std::endl;
    range_iterator = map.equal_range(123);
    for (ft::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (1)" << std::endl;
    range_iterator = map.equal_range(1);
    if (range_iterator.first == map.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    if (range_iterator.second == map.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    range_iterator = map.equal_range(4554);
    for (ft::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    if (range_iterator.second == map.end())
        std::cout << "Equal range(4554) have no element greater than key." << std::endl;
}

void    map_equal_range_const_custom()
{
    std::cout << "Map Equal Range CONST CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> range_iterator;

    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    map.insert(ft::make_pair(123, 123));
    map.insert(ft::make_pair(42, 42));
    map.insert(ft::make_pair(4554, -1));
    const ft::map<int, int>  map2(map.begin(), map.end());
    range_iterator = map2.equal_range(42);
    for (ft::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (5)" << std::endl;
    range_iterator = map2.equal_range(5);
	std::cout << "it->first : " << range_iterator.first->first << std::endl;
    std::cout << "it->first : " << range_iterator.second->first << std::endl;
    std::cout << "New equal_range call (123)" << std::endl;
    range_iterator = map2.equal_range(123);
    for (ft::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (1)" << std::endl;
    range_iterator = map2.equal_range(1);
    if (range_iterator.first == map2.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    if (range_iterator.second == map2.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    range_iterator = map2.equal_range(4554);
    for (ft::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    if (range_iterator.second == map2.end())
        std::cout << "Equal range(4554) have no element greater than key." << std::endl;
}


void    lower_bound_map_custom()
{
    std::cout << "Map lower bound CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator it;
    ft::map<int, int>::const_iterator cit;

    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    const ft::map<int, int>  map2(map.begin(), map.end());
    for (int i = 1; i < 5; i++)
    {
        it = map.lower_bound(i);
        std::cout << "first : " << it->first << std::endl;
        cit = map2.lower_bound(i);
        std::cout << "first : " << cit->first << std::endl;
    }
}

void    upper_bound_map_custom()
{
    std::cout << "Map upper bound CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator it;
    ft::map<int, int>::const_iterator cit;

    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    const ft::map<int, int>  map2(map.begin(), map.end());
    for (int i = 1; i < 4; i++)
    {
        it = map.upper_bound(i);
        std::cout << "first : " << it->first << std::endl;
        cit = map2.upper_bound(i);
        std::cout << "first : " << cit->first << std::endl;
    }
}