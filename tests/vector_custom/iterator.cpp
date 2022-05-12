#include "iterator.hpp"

void    iterator_test_custom()
{
    std::cout << "Iterator custom" << std::endl;
    ft::vector<int>    vec;
    ft::vector<int>::iterator it = vec.begin();
    ft::vector<int>::const_iterator cit(it);
    cit = it;
    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    for (ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (ft::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
       std::cout << *it << std::endl;
    ft::vector<int>::const_iterator eit = vec.end();
    std::cout << "base : " << *it.base() << std::endl;
    it -= 1;
    it + 1;
    it - 1;
    it += 1;
    it - it;
    for (ft::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
        std::cout << *it << std::endl;
}

void    iterator_empty_custom()
{
    std::cout << "iterator empty custom" << std::endl;
    ft::vector<int>    vec;

    for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}