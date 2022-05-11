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

void    rite()
{
    const int size = 5;
	std::vector<int> vct(size);
	std::vector<int>::reverse_iterator it = vct.rbegin();
	std::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	//printSize(vct, true);
}