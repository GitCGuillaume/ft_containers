#include "reverse_iterator.hpp"

void    reverse_iterator()
{
    std::cout << "Reverse iterator" << std::endl;
    NAMESPACE::vector<int>    vec;
	NAMESPACE::vector<int>::reverse_iterator it(vec.rbegin());
	NAMESPACE::vector<int>::const_reverse_iterator ite(vec.rend());

	it = vec.rbegin();
	ite = vec.rbegin();
    static_cast<void>(it);
    static_cast<void>(ite);
    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    for (NAMESPACE::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
    for (NAMESPACE::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
       std::cout << *rit << std::endl;
    NAMESPACE::vector<int>::reverse_iterator rit = vec.rend();
    std::cout << "base : " << *rit.base() << std::endl;
    NAMESPACE::vector<int>::reverse_iterator rit_2 = vec.rbegin();
    std::cout << "rit += 1 : " << *(rit_2 += 2) << std::endl;
    std::cout << "rit -= 1 : " << *(rit_2 -= 1) << std::endl;
    rit_2 + 1;
    rit_2 - 1;
    for (NAMESPACE::vector<int>::reverse_iterator rit = vec.rend() - 1; rit != vec.rbegin(); rit--)
        std::cout << *rit << std::endl;
}

void    reverse_iterator_empty()
{
    std::cout << "Reverse iterator empty" << std::endl;
    NAMESPACE::vector<int>    vec;

    for (NAMESPACE::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
        std::cout << *rit << std::endl;
}