#include "iterator_forward.hpp"

void	iterator_assign_forward()
{
	NAMESPACE::vector<int>	vec;

	std::cout << "Iterator assign FORWARD" << std::endl;
	vec.assign(3, 'b');
	vec.assign(3, 'b');
	NAMESPACE::vector<int>::iterator	it_1 = vec.begin();
	std::cout << *it_1 << std::endl;
	std::cout << "POSTFIX" << std::endl;
	for (NAMESPACE::vector<int>::iterator	it_1 = vec.begin(); it_1 != vec.end(); it_1++)
	{
		std::cout << "base : " << *it_1.base();
		std::cout << *it_1 << std::endl;
	}
	std::cout << "PREFIX" << std::endl;
	for (NAMESPACE::vector<int>::iterator	it_1 = vec.begin(); it_1 != vec.end(); ++it_1)
		std::cout << *it_1 << std::endl;
	std::cout << "Capacity vector " << vec.capacity() << std::endl;
}

void	iterator_assign_first_last_forward()
{
	std::cout << "Iterator assign FIRST LAST FORWARD" << std::endl;
	NAMESPACE::vector<int>	vec_1;
	NAMESPACE::vector<int>	vec_2;
	NAMESPACE::vector<int>::iterator	it_1;
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

void	iterator_input_assign()
{
	std::cout << "Input Tag Iterator Assign" << std::endl;
	NAMESPACE::vector<char>	vec;
    NAMESPACE::vector<char>	vec_2;
    NAMESPACE::vector<char>	vec_3;
	std::istringstream str("1 2 3");
    std::istringstream str2("1 2 34");
    std::istringstream str3("1 2 3 4");

	vec.assign(std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_2.assign(std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_3.assign(std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
	for (NAMESPACE::vector<char>::iterator it_start = vec.begin(); it_start != vec.end(); ++it_start)
		std::cout << *it_start << std::endl;
	std::cout << "Assign range constructor : " << vec.capacity() << std::endl;
    std::cout << "Assign size constructor : " << vec.size() << std::endl;
    for (NAMESPACE::vector<char>::iterator it_start = vec_2.begin(); it_start != vec_2.end(); ++it_start)
		std::cout << *it_start << std::endl;
	std::cout << "Assign range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Assign size constructor : " << vec_2.size() << std::endl;
    for (NAMESPACE::vector<char>::iterator it_start = vec_3.begin(); it_start != vec_3.end(); ++it_start)
		std::cout << *it_start << std::endl;
	std::cout << "Assign range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Assign size constructor : " << vec_3.size() << std::endl;
}