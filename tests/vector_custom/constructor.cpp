#include "constructor.hpp"

void    default_custom_constructor()
{
    ft::vector<int> vec;
    const ft::vector<int> const_vec;

    std::cout << "Capacity custom default constructor : " << vec.capacity() << std::endl;
    std::cout << "Size custom default constructor : " << vec.size() << std::endl;
    std::cout << "Capacity custom default const constructor : " << const_vec.capacity() << std::endl;
    std::cout << "Size custom default const constructor : " << const_vec.size() << std::endl;
}

void    allocator_custom_constructor()
{
    ft::vector<int> vec;

    vec.assign(5, 1);
    ft::vector<int> vec_alloc(vec.get_allocator());
    std::cout << "Capacity custom allocator constructor : " << vec_alloc.capacity() << std::endl;
    std::cout << "Size custom allocator constructor : " << vec_alloc.size() << std::endl;
}

void    allocator_custom_count_copy_constructor()
{
    std::cout << "Allocator custom count copies" << std::endl;
	ft::vector<std::string> vec(3, "str value");
    for (ft::vector<std::string>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}