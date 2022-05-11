#include "iterator.hpp"

void    iterator_test()
{
    std::cout << "Iterator" << std::endl;
    std::vector<int>    vec;

    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (std::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
       std::cout << *it << std::endl;
    std::vector<int>::const_iterator it = vec.end();
    std::cout << "base : " << *it.base() << std::endl;
    it -= 1;
    it + 1;
    it - 1;
    it += 1;
    it - it;
    for (std::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
        std::cout << *it << std::endl;
}

void    iterator_empty()
{
    std::cout << "iterator empty" << std::endl;
    std::vector<int>    vec;

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}