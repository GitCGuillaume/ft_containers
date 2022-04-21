#include "includes/iterators/iterator_traits.hpp"
#include "includes/iterators/RandomAccessIterator.hpp"
#include "includes/containers/vector.hpp"
#include <iostream>
#include "includes/iterators/reverse_iterator.hpp"
#include <vector>

void	test_assign1()
{
	std::vector<int>	lst;
	/*for (int i = 0; i < 7; i++)
	{
		lst.push_back(i);
	}*/
	lst.assign(3, 'a');
	std::vector<int>::iterator	it1 = lst.begin();
	std::vector<int>::iterator	it2 = lst.end();
	std::cout << *it1 << std::endl;
	std::cout << *it2 << std::endl;
	for (std::vector<int>::iterator	it1 = lst.begin(); it1 != lst.end(); it1++)
	{
		std::cout << *it1 << std::endl;
	}
	std::cout << "Capacity std::vector " << lst.capacity() << std::endl;
}

void	test_ft_assign1()
{
	ft::vector<int>	vec;

	vec.assign(3, 'b');
	ft::vector<int>::iterator	it1 = vec.begin();
	ft::vector<int>::iterator	it2 = vec.end();
	std::cout << *it1 << std::endl;
	std::cout << *it2 << std::endl;
	for (ft::vector<int>::iterator	it1 = vec.begin(); it1 != vec.end(); it1++)
	{
		std::cout << *it1 << std::endl;
	}
	std::cout << "Capacity ft::vector " << vec.capacity() << std::endl;
}

/*
	std::vector<int>	lst = {1,2} == C++11
*/
int	main(void)
{
	test_assign1();
	test_ft_assign1();
	/*std::vector<int>	lst;
	std::cout << "Capacity std::vector " << lst.capacity() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		lst.push_back(i);
	}
	//lst.assign(27, 'a');
	lst.assign(5, 'b');
	std::cout << "Capacity std::vector " << lst.capacity() << std::endl;
	for (std::vector<int>::reverse_iterator	it1 = lst.rbegin(); it1 != lst.rend(); it1++)
	{
		std::cout << *it1 << std::endl;
		//std::cout << "base : " << *it1.base() << std::endl;
	}*/
	//std::cout << "lst[0]=" << lst[0];
	/*int i = 0;
	
	for (i = 0; i < 20; i++)
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
	std::cout << "Capacity std::vector " << lst.capacity() << std::endl;*/
	return (0);
}
