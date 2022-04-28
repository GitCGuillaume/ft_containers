#include "constructor.hpp"

void    default_constructor()
{
    std::vector<int> vec;
    const std::vector<int> const_vec;

    std::cout << "Capacity default constructor : " << vec.capacity() << std::endl;
    std::cout << "Size default constructor : " << vec.size() << std::endl;
    std::cout << "Capacity default const constructor : " << const_vec.capacity() << std::endl;
    std::cout << "Size default const constructor : " << const_vec.size() << std::endl;
}

void    allocator_constructor()
{
    std::vector<int> vec;

    vec.assign(5, 1);
    std::vector<int> vec_alloc(vec.get_allocator());
    std::cout << "Capacity allocator constructor : " << vec_alloc.capacity() << std::endl;
    std::cout << "Size allocator constructor : " << vec_alloc.size() << std::endl;
}

void    allocator_count_constructor()
{
    std::cout << "Allocator count" << std::endl;
    std::vector<std::string> vec(3, "str value");
    std::cout << "Capacity count allocator constructor : " << vec.capacity() << std::endl;
    std::cout << "Size count allocator constructor : " << vec.size() << std::endl;
	for (std::vector<std::string>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

void    allocator_iterator()
{
     std::cout << "Allocator iterator" << std::endl;
    std::vector<float>  vec(3, 1.000000);
    std::vector<float>  vec_2(vec.begin(), vec.end());
    std::cout << "Capacity count allocator constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Size count allocator constructor : " << vec_2.size() << std::endl;
    for (std::vector<float>::iterator	it = vec_2.begin(); it != vec_2.end(); it++)
		std::cout << *it << std::endl;
}