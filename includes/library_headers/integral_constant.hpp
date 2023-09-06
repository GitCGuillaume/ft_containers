#ifndef INTEGRAL_CONSTANT
# define INTEGRAL_CONSTANT

namespace ft
{
    template<class T, T v>
    struct  integral_constant
    {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T,v>  type;
    };
    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>   false_type;
}

#endif