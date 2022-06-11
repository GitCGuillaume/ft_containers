#include "iterator_backward.hpp"

void	test_ft_assign1_backward()
{
	ft::vector<int>	vec;

	vec.assign(3, 'b');
	std::cout << "TEST_FT_ASSIGN1_BACKWARD CUSTOM" << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity ft::vector " << vec.capacity() << std::endl;
}

void	test_ft_assign_it_backward()
{
	ft::vector<int>	vec_1;
	ft::vector<int> vec_2;
	ft::vector<int>::iterator	it_1;
	char	a = 'a';

	std::cout << "TEST_FT_ASSIGN_IT_BACKWARD CUSTOM" << std::endl;
	vec_1.assign(3, a++);
	it_1 = vec_1.begin();
	vec_2.assign(it_1, vec_1.end());
	std::cout << "PREFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (ft::vector<int>::iterator	it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity ft::vector " << vec_2.capacity() << std::endl;
}