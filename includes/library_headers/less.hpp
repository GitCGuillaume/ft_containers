#ifndef FT_LESS_HPP
# define FT_LESS_HPP

#include "binary_function.hpp"

/* 
    https://en.cppreference.com/w/cpp/utility/functional/less
    compare less
*/

namespace ft
{
    template<class T>
    struct  less : public binary_function<T, T, bool>
    {
        bool    operator()(T const & lhs, T const & rhs) const
        {
            return (lhs < rhs);
        }
    };
}

#endif
