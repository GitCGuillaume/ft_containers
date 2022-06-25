#include "iterator_forward.hpp"

void	iterator_assign_backward()
{
	ft::vector<int>	vec;

	vec.assign(3, 'b');
	std::cout << "Iterator function assign BACKWARD" << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity vector " << vec.capacity() << std::endl;
}

void	iterator_assign_first_last_backward()
{
	ft::vector<int>	vec_1;
	ft::vector<int>	vec_2;
	ft::vector<int>::iterator	it_1;
	char	a = 'a';

	std::cout << "ASSIGN FIRST LAST BACKWARD" << std::endl;
	vec_1.assign(3, a++);
	it_1 = vec_1.begin();
	vec_2.assign(it_1, vec_1.end());
	std::cout << "POSTFIX" << std::endl;
	for (it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity vector " << vec_2.capacity() << std::endl;
}