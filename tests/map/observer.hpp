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

#include <map>
#include <iostream>
#include "../../includes/containers/map.hpp"
#include "../../includes/library_headers/less.hpp"
#include "../../includes/library_headers/pair.hpp"

void    test_keycomp();
void    test_keycomp();
void    test_value_comp();

#endif