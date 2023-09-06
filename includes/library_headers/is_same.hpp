#ifndef IS_SAME_HPP
# define IS_SAME_HPP

#include "integral_constant.hpp"

namespace ft
{
    /* False type and true type into is_integral.hpp */
    template<typename T, typename U>
    struct  is_same : public ft::false_type{};
    template<typename T>
    struct  is_same<T, T> : public ft::true_type{};
}

#endif
