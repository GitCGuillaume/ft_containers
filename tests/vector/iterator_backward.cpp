#include "iterator_forward.hpp"

void	test_std_assign1_backward()
{
	std::vector<int>	vec;

	vec.assign(3, 'b');
	std::cout << "TEST_STD_ASSIGN1_BACKWARD" << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (std::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (std::vector<int>::iterator	it_1 = vec.end() - 1; it_1 != vec.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity std::vector " << vec.capacity() << std::endl;
}

void	test_std_assign_it_backward()
{
	std::vector<int>	vec_1;
	std::vector<int> vec_2;
	std::vector<int>::iterator	it_1;
	char	a = 'a';

	std::cout << "TEST_STD_ASSIGN_IT_BACKWARD" << std::endl;
	vec_1.assign(3, a++);
	it_1 = vec_1.begin();
	vec_2.assign(it_1, vec_1.end());
	std::cout << "POSTFIX" << std::endl;
	for (it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); it_1--)
		std::cout << *it_1 << std::endl;
	std::cout << "PREFIX" << std::endl;
	for (it_1 = vec_2.end() - 1; it_1 != vec_2.begin(); --it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity std::vector " << vec_2.capacity() << std::endl;
}