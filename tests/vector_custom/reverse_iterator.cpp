#include "reverse_iterator.hpp"

void    reverse_iterator_custom()
{
    std::cout << "Reverse iterator custom" << std::endl;
    ft::vector<int>    vec;

    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    for (ft::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
    for (ft::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
       std::cout << *rit << std::endl;
    ft::vector<int>::reverse_iterator rit = vec.rend();
    std::cout << "base : " << *rit.base() << std::endl;
    rit -= 1;
    rit + 1;
    rit - 1;
    rit += 1;
    for (ft::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
        std::cout << *rit << std::endl;
}

void    reverse_iterator_empty_custom()
{
    std::cout << "Reverse iterator empty custom" << std::endl;
    ft::vector<int>    vec;

    for (ft::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
}