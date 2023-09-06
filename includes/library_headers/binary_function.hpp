#ifndef BINARYFUNCTION
# define BINARYFUNCTION

namespace ft
{
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
}

#endif