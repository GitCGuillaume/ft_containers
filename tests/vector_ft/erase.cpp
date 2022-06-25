#include "erase.hpp"

void    erase()
{
    std::cout << "Erase" << std::endl;
    ft::vector<double>  vec;
    for (double i = 0.000000; i < 8.000000; i++)
        vec.insert(vec.begin(), i);
    vec.insert(vec.end(), 9);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for  (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    ft::vector<double>::iterator it_1 = vec.begin();
    ft::vector<double>::iterator it_2 = vec.begin() + 3;
    std::cout << "return : " << *vec.erase(vec.begin() + 2) << std::endl;
    std::cout << "return : " << *vec.erase(vec.end() - 2) << std::endl;
    vec.erase(vec.end() - 1);
    vec.erase(vec.end() - 1);
    for (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it_1 : " << *it_1 << std::endl;
    std::cout << "it_2 : " << *it_2 << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_30k()
{
    std::cout << "Erase 30k" << std::endl;

    ft::vector<double>  vec;
    for (double i = 0.000000; i < 30000.000000; i++)
        vec.insert(vec.end(), i);
    for (double i = 0.000000; i < 30000.000000; i++)
        vec.erase(vec.begin());
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    erase_iterator()
{
    std::cout << "Erase iterator" << std::endl;

    ft::vector<double>  vec;
    for (double i = 1.000000; i < 10000.000000; i++)
        vec.insert(vec.end(), i);
    std::cout << "return iterator erase : " << *vec.erase(vec.begin() + 1, vec.end() - 5) << std::endl;
    for (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "return iterator erase : " << *vec.erase(vec.begin(), vec.end()) << std::endl;
    for (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    ft::vector<double>  vec_2;
    vec_2.insert(vec_2.end(), 1.000000);
    std::cout << "return iterator erase : " << *vec_2.erase(vec_2.begin(), vec_2.end()) << std::endl;
}