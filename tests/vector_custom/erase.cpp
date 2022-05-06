#include "erase.hpp"

void    erase_custom()
{
    std::cout << "Erase custom" << std::endl;
    ft::vector<double>  vec;
    for (double i = 0.000000; i < 5.000000; i++)
        vec.insert(vec.begin(), i);
    vec.insert(vec.end(), 9);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for  (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    ft::vector<double>::iterator it1 = vec.begin();
    ft::vector<double>::iterator it2 = vec.begin() + 3;
    std::cout << "return : " << *vec.erase(vec.begin() + 2) << std::endl;
    std::cout << "return : " << *vec.erase(vec.end() - 1) << std::endl;
    for (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it1 : " << *it1 << std::endl;
    std::cout << "it2 : " << *it2 << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_30k_custom()
{
    std::cout << "Erase 30k custom" << std::endl;

    ft::vector<double>  vec;
    for (double i = 0.000000; i < 30000.000000; i++)
        vec.insert(vec.end(), i);
    vec.erase(vec.begin() + 2);
    vec.erase(vec.begin() + 10000);
    vec.erase(vec.end() - 1);
    for (double i = 0.000000; i < 28000.000000; i++)
        vec.insert(vec.end(), i);
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_iterator_custom()
{
    std::cout << "Erase iterator custom" << std::endl;

    ft::vector<double>  vec;
    for (double i = 0.000000; i < 10.000000; i++)
        vec.insert(vec.end(), i);
    vec.erase(vec.begin() + 2, vec.begin() + 7);
    for (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}