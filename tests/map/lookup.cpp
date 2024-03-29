#include "lookup.hpp"

static void    exist(NAMESPACE::map<int, int>::const_iterator it, NAMESPACE::map<int, int>& map)
{
    if (it == map.end())
        std::cout << "Does not exist" << std::endl;
    else
        std::cout << "Exist" << std::endl;
}

void    lookup_find()
{
    std::cout << "Map find" << std::endl;
    NAMESPACE::map<int, int>  map;

    exist(map.find(0), map);
    map.insert(NAMESPACE::make_pair(10, 0));
    map.insert(NAMESPACE::make_pair(0, 0));
    map.insert(NAMESPACE::make_pair(-10, 0));
    map.insert(NAMESPACE::make_pair(42254, 0));
    map.insert(NAMESPACE::make_pair(42, 0));
    map.insert(NAMESPACE::make_pair(21, 0));
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
    NAMESPACE::map<int, int>  map;
    map[1] = 1;
    map[1] = 0;
    map[0] = 1;
    NAMESPACE::map<int, int>  map_2;
    std::cout << map.count(1) << std::endl;
    std::cout << map.count(0) << std::endl;
    std::cout << map.count(2) << std::endl;
    std::cout << map_2.count(0) << std::endl;
}

void    map_equal_range()
{
    std::cout << "Map Equal Range" << std::endl;
    NAMESPACE::map<int, int>  map;
    NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, NAMESPACE::map<int, int>::iterator> range_iterator;

    map.insert(NAMESPACE::make_pair(2, 12));
    map.insert(NAMESPACE::make_pair(3, -1));
    map.insert(NAMESPACE::make_pair(4, 145));
    map.insert(NAMESPACE::make_pair(123, 123));
    map.insert(NAMESPACE::make_pair(42, 42));
    map.insert(NAMESPACE::make_pair(4554, -1));
    range_iterator = map.equal_range(42);
    for (NAMESPACE::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (5)" << std::endl;
    range_iterator = map.equal_range(5);
	std::cout << "it->first : " << range_iterator.first->first << std::endl;
    std::cout << "it->first : " << range_iterator.second->first << std::endl;
    std::cout << "New equal_range call (123)" << std::endl;
    range_iterator = map.equal_range(123);
    for (NAMESPACE::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (1)" << std::endl;
    range_iterator = map.equal_range(1);
    if (range_iterator.first == map.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    if (range_iterator.second == map.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    range_iterator = map.equal_range(4554);
    for (NAMESPACE::map<int, int>::iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    if (range_iterator.second == map.end())
        std::cout << "Equal range(4554) have no element greater than key." << std::endl;
}

void    map_equal_range_const()
{
    std::cout << "Map Equal Range CONST" << std::endl;
    NAMESPACE::map<int, int>  map;
    NAMESPACE::pair<NAMESPACE::map<int, int>::const_iterator, NAMESPACE::map<int, int>::const_iterator> range_iterator;

    map.insert(NAMESPACE::make_pair(2, 12));
    map.insert(NAMESPACE::make_pair(3, -1));
    map.insert(NAMESPACE::make_pair(4, 145));
    map.insert(NAMESPACE::make_pair(123, 123));
    map.insert(NAMESPACE::make_pair(42, 42));
    map.insert(NAMESPACE::make_pair(4554, -1));
    const NAMESPACE::map<int, int>  map_2(map.begin(), map.end());
    range_iterator = map_2.equal_range(42);
    for (NAMESPACE::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (5)" << std::endl;
    range_iterator = map_2.equal_range(5);
	std::cout << "it->first : " << range_iterator.first->first << std::endl;
    std::cout << "it->first : " << range_iterator.second->first << std::endl;
    std::cout << "New equal_range call (123)" << std::endl;
    range_iterator = map_2.equal_range(123);
    for (NAMESPACE::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    std::cout << "New equal_range call (1)" << std::endl;
    range_iterator = map_2.equal_range(1);
    if (range_iterator.first == map_2.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    if (range_iterator.second == map_2.begin())
        std::cout << "Equal range(1) have no element not less than key." << std::endl;
    range_iterator = map_2.equal_range(4554);
    for (NAMESPACE::map<int, int>::const_iterator	it = range_iterator.first; it != range_iterator.second; it++)
		std::cout << "it->first : " << it->first << std::endl;
    if (range_iterator.second == map_2.end())
        std::cout << "Equal range(4554) have no element greater than key." << std::endl;
}

void    lower_bound_map()
{
    std::cout << "Map lower bound" << std::endl;
    NAMESPACE::map<int, int>  map;
    NAMESPACE::map<int, int>::iterator it;
    NAMESPACE::map<int, int>::const_iterator cit;

    map.insert(NAMESPACE::make_pair(2, 12));
    map.insert(NAMESPACE::make_pair(3, -1));
    map.insert(NAMESPACE::make_pair(4, 145));
    const NAMESPACE::map<int, int>  map_2(map.begin(), map.end());
    for (int i = -1; i < 5; i++)
    {
        it = map.lower_bound(i);
        std::cout << "first : " << it->first << std::endl;
        cit = map_2.lower_bound(i);
        std::cout << "c_first : " << cit->first << std::endl;
    }
    it = map.lower_bound(5);
    std::cout << "it low bound == end" << (it == map.end()) << std::endl;
    cit = map_2.lower_bound(5);
    std::cout << "cit low bound == end" << (cit == map_2.end()) << std::endl;
}

void    upper_bound_map()
{
    std::cout << "Map upper bound" << std::endl;
    NAMESPACE::map<int, int>  map;
    NAMESPACE::map<int, int>::iterator it;
    NAMESPACE::map<int, int>::const_iterator cit;

    map.insert(NAMESPACE::make_pair(2, 12));
    map.insert(NAMESPACE::make_pair(3, -1));
    map.insert(NAMESPACE::make_pair(4, 145));
    const NAMESPACE::map<int, int>  map_2(map.begin(), map.end());
    for (int i = -1; i < 4; i++)
    {
        it = map.upper_bound(i);
        std::cout << "first : " << it->first << std::endl;
        cit = map_2.upper_bound(i);
        std::cout << "c_first : " << cit->first << std::endl;
    }
    it = map.lower_bound(5);
    std::cout << "it upper bound == end" << (it == map.end()) << std::endl;
    cit = map_2.lower_bound(5);
    std::cout << "cit upper bound == end" << (cit == map_2.end()) << std::endl;
}
