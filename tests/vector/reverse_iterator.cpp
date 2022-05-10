#include "reverse_iterator.hpp"

void    reverse_iterator()
{
    std::cout << "Reverse iterator" << std::endl;
    std::vector<int>    vec;

    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
    for (std::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
       std::cout << *rit << std::endl;
    std::vector<int>::reverse_iterator rit = vec.rend();
    std::cout << "base : " << *rit.base() << std::endl;
    rit -= 1;
    rit + 1;
    rit - 1;
    rit += 1;
    for (std::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
        std::cout << *rit << std::endl;
}

void    reverse_iterator_empty()
{
    std::cout << "Reverse iterator empty" << std::endl;
    std::vector<int>    vec;

    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
}