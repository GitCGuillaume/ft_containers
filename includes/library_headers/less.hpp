#ifndef FT_LESS_HPP
# define FT_LESS_HPP

/*
    Base class for creating function objetcts with 2 arguments.
*/

template<class Arg1, class Arg2, class Result>
struct  binary_function
{
    typedef Arg1    first_argument_type;
    typedef Arg2    second_argument_type;
    typedef Result  result_type;
};

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