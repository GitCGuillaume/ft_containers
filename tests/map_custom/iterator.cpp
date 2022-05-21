#include "iterator.hpp"

void    forward_iterator_map_default_custom()
{
    std::cout << "FORWARD MAP ITERATOR DEFAULT CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator  it = map.begin();
    std::cout << "first : " << it->first << std::endl;
    std::cout << "second : " << it->second << std::endl;
}