#include "includes/iterators/iterator_traits.hpp"
#include "includes/iterators/RandomAccessIterator.hpp"
#include "includes/containers/vector.hpp"
#include <iostream>
#include "includes/iterators/reverse_iterator.hpp"
#include <vector>

/*
	std::vector<int>	lst = {1,2} == C++11
*/
int	main(void)
{
	std::vector<int>	lst;
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		lst.push_back(i);
	}
	for (std::vector<int>::iterator	it1 = lst.begin(); it1 != lst.end(); it1++)
		std::cout << *it1 << std::endl;
	for (std::vector<int>::reverse_iterator	it1 = lst.rbegin(); it1 != lst.rend(); it1++)
	{
		std::cout << *it1 << std::endl;
		//std::cout << "base : " << *it1.base() << std::endl;
	}
	ft::vector<int>::iterator	it2;
	ft::vector<int>::reverse_iterator	it3;
	ft::vector<int>	test;
	ft::vector<int>	test2;
	test = test2;
	
	return (0);
}
