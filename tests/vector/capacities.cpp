#include "capacities.hpp"

void    empty()
{
    std::cout << "Empty" << std::endl;
    NAMESPACE::vector<int>    vec;

    std::cout << "Is empty : " << vec.empty() << std::endl;
    vec.assign(1, 2);
    std::cout << "Is not empty " << vec.empty() << std::endl;
}

void    max_size()
{
    std::cout << "Max size" << std::endl;
    NAMESPACE::vector<int>    vec;

    std::cout << vec.max_size() << std::endl;
}

void    reserve_error()
{
    std::cout << "Reserve error" << std::endl;
    NAMESPACE::vector<int>    vec;

    try
    {
        vec.reserve(vec.max_size() + 1);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    reserve_test()
{
    std::cout << "Reserve" << std::endl;
    NAMESPACE::vector<int>    vec(1,1);
    for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << vec.capacity();
    vec.assign(5, 1);
    std::cout << vec.capacity();
    for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.assign(150000, 1);
    std::cout << vec.capacity() << std::endl;
}