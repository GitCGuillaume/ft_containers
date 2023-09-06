#include "iterator.hpp"

void    iterator_test()
{
    std::cout << "Iterator" << std::endl;
    NAMESPACE::vector<int>    vec;
    NAMESPACE::vector<int>::iterator it = vec.begin();
    NAMESPACE::vector<int>::const_iterator cit(it);
    cit = it;
    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    it = vec.begin();
    cit = it;
    if (it == cit)
        std::cout << "COMPARE SAME = ( it: " << *it << " cit: " << *cit << " )" << std::endl;
    for (NAMESPACE::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (NAMESPACE::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
       std::cout << *it << std::endl;
    NAMESPACE::vector<int>::const_iterator eit = vec.end();
    static_cast<void>(eit);
    it = vec.begin();
    std::cout << "base : " << *it.base() << std::endl;
    it -= 1;
    it + 1;
    it - 1;
    it += 1;
    it - it;
    for (NAMESPACE::vector<int>::const_iterator it = vec.end() - 1; it != vec.begin(); it--)
        std::cout << *it << std::endl;
}

void    iterator_empty()
{
    std::cout << "iterator empty" << std::endl;
    NAMESPACE::vector<int>    vec;

    for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}