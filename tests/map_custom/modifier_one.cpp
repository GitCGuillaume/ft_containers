#include "modifier_one.hpp"

void    simple_clear_custom()
{
    ft::map<int, int>   map;

    for (short int i = 0; i < 5000; i++)
        map[i] = i;
    map.clear();
}