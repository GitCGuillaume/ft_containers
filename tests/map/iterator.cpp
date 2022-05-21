#include "iterator.hpp"

void    forward_iterator_map_default()
{
    std::cout << "FORWARD MAP ITERATOR DEFAULT" << std::endl;
    std::map<int, int>  map;
    std::map<int, int>::iterator  it = map.begin();
    std::cout << "first : " << it->first << std::endl;
    std::cout << "second : " << it->second << std::endl;
}