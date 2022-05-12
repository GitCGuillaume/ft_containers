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

void    rite2()
{
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it(vct.rbegin());
	ft::vector<int>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	//printSize(vct, 1);

	it = vct.rbegin();
	ite = vct.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	//it->m();
	//ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	//(*it).m();
	//(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;
}