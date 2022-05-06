#include "erase.hpp"

void    erase()
{
    std::cout << "Erase" << std::endl;
    std::vector<double>  vec;
    for (double i = 0.000000; i < 5.000000; i++)
        vec.insert(vec.begin(), i);
    vec.insert(vec.end(), 9);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::vector<double>::iterator it1 = vec.begin();
    std::vector<double>::iterator it2 = vec.begin() + 3;
    std::cout << "return : " << *vec.erase(vec.begin() + 2) << std::endl;
    std::cout << "return : " << *vec.erase(vec.end() - 1) << std::endl;
    for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it1 : " << *it1 << std::endl;
    std::cout << "it2 : " << *it2 << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_30k()
{
    std::cout << "Erase 30k" << std::endl;

    std::vector<double>  vec;
    for (double i = 0.000000; i < 30000.000000; i++)
        vec.insert(vec.end(), i);
    vec.erase(vec.begin() + 2);
    vec.erase(vec.begin() + 10000);
    vec.erase(vec.end() - 1);
    for (double i = 0.000000; i < 28000.000000; i++)
        vec.insert(vec.end(), i);
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_iterator()
{
    std::cout << "Erase iterator" << std::endl;

    std::vector<double>  vec;
    for (double i = 0.000000; i < 10.000000; i++)
        vec.insert(vec.end(), i);
    vec.erase(vec.begin() + 2, vec.begin() + 7);
    for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}