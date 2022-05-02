#include "capacities.hpp"

void    empty()
{
    std::cout << "Empty" << std::endl;
    std::vector<int>    vec;

    std::cout << "Is empty : " << vec.empty() << std::endl;
    vec.assign(1, 2);
    std::cout << "Is not empty " << vec.empty() << std::endl;
}

void    max_size()
{
    std::cout << "Max size" << std::endl;
    std::vector<int>    vec;

    std::cout << vec.max_size() << std::endl;
}

void    reserve_error()
{
    std::vector<int>    vec;
    try
    {
        vec.resize(vec.max_size() + 1);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    reserve_test()
{
    std::cout << "Reserve" << std::endl;
    std::vector<int>    vec(1,1);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << vec.capacity();
    vec.assign(5, 1);
    std::cout << vec.capacity();
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.assign(50000, 1);
    std::cout << vec.capacity() << std::endl;
}