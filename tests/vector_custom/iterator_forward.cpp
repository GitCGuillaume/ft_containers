#include "iterator_forward.hpp"

void	test_ft_assign1_forward()
{
	ft::vector<int>	vec;

	vec.assign(3, 'b');
	ft::vector<int>::iterator	it_1 = vec.begin();
	ft::vector<int>::iterator	it_2 = vec.end();
	std::cout << *it_1 << std::endl;
	//undefined behavior
	//std::cout << *it_2 << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec.begin(); it_1 != vec.end(); it_1++)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity ft::vector " << vec.capacity() << std::endl;
}

void	test_ft_assign_it_forward()
{
	ft::vector<int>	vec_1;
	ft::vector<int> vec_2;
	ft::vector<int>::iterator	it_1;
	char	a = 'a';

	vec_1.assign(3, a++);
	it_1 = vec_1.begin();
	vec_2.assign(it_1, vec_1.end());
	for (it_1 = vec_2.begin(); it_1 != vec_2.end(); it_1++)
		std::cout << *it_1 << std::endl;
}