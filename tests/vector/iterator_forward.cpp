#include "iterator_forward.hpp"

void	iterator_assign_forward()
{
	std::vector<int>	vec;

	std::cout << "Iterator assign FORWARD" << std::endl;
	vec.assign(3, 'b');
	vec.assign(3, 'b');
	std::vector<int>::iterator	it_1 = vec.begin();
	std::cout << *it_1 << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (std::vector<int>::iterator	it_1 = vec.begin(); it_1 != vec.end(); it_1++)
	{
		std::cout << "base : " << it_1.base();
		std::cout << *it_1 << std::endl;
	}
	std::cout << "PREFIX" << std::endl;
	for (std::vector<int>::iterator	it_1 = vec.begin(); it_1 != vec.end(); ++it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity vector " << vec.capacity() << std::endl;
}

void	iterator_assign_first_last_forward()
{
	std::cout << "Iterator assign FIRST LAST FORWARD" << std::endl;
	std::vector<int>	vec_1;
	std::vector<int>	vec_2;
	std::vector<int>::iterator	it_1;
	char	a = 'a';

	vec_1.assign(3, a++);
	it_1 = vec_1.begin();
	vec_2.assign(it_1, vec_1.end());
	std::cout << "POSTFIX" << std::endl;
	for (it_1 = vec_2.begin(); it_1 != vec_2.end(); it_1++)
		std::cout << *it_1 << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (it_1 = vec_2.begin(); it_1 != vec_2.end(); ++it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity vector " << vec_2.capacity() << std::endl;
}