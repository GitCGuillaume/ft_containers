#ifndef OBSERVER_MAP_HPP
# define OBSERVER_MAP_HPP

template<typename T>
struct  s_cmp
{
    bool    operator()(T const & lhs, T const & rhs) const
    {
        return (lhs > rhs);
    }
};

#include <iostream>
#include <map>
#include "../../includes/containers/map.hpp"

void    test_keycomp();
void    test_keycomp();
void    test_value_comp();

#endif