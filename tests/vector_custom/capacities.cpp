#include "capacities.hpp"

void    empty_custom()
{
    std::cout << "Empty custom" << std::endl;
    ft::vector<int>    vec;

    std::cout << "Is empty : " << vec.empty() << std::endl;
    vec.assign(1, 2);
    std::cout << "Is not empty " << vec.empty() << std::endl;
}

void    max_size_custom()
{
    std::cout << "Max size custom" << std::endl;
    ft::vector<int>    vec;

    std::cout << vec.max_size() << std::endl;
}

void    reserve_test_custom()
{
    std::cout << "Reserve custom" << std::endl;
    ft::vector<int>    vec(1,1);
    for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << vec.capacity();
    vec.assign(5, 1);
    std::cout << vec.capacity();
    for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.assign(50000, 1);
    std::cout << vec.capacity() << std::endl;
}