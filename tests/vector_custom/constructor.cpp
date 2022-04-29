#include "constructor.hpp"

void    default_custom_constructor()
{
    ft::vector<int> vec;
    const ft::vector<int> const_vec;

    std::cout << "Default custom constructor" << std::endl;
    std::cout << "Capacity custom default constructor : " << vec.capacity() << std::endl;
    std::cout << "Size custom default constructor : " << vec.size() << std::endl;
    std::cout << "Capacity custom default const constructor : " << const_vec.capacity() << std::endl;
    std::cout << "Size custom default const constructor : " << const_vec.size() << std::endl;
}

void    allocator_custom_constructor()
{
    ft::vector<int> vec;

    std::cout << "Allocator custom vec.get_allocator()" << std::endl;
    vec.assign(5, 1);
    ft::vector<int> vec_alloc(vec.get_allocator());
    std::cout << "Capacity custom allocator constructor : " << vec_alloc.capacity() << std::endl;
    std::cout << "Size custom allocator constructor : " << vec_alloc.size() << std::endl;
}

void    allocator_custom_count_constructor()
{
    std::cout << "Allocator custom count constructor" << std::endl;
	ft::vector<std::string> vec(3, "str value");
    std::cout << "Capacity custom count allocator constructor : " << vec.capacity() << std::endl;
    std::cout << "Size custom count allocator constructor : " << vec.size() << std::endl;
    for (ft::vector<std::string>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

void    allocator_custom_iterator()
{
    std::cout << "Allocator iterator constructor" << std::endl;
    ft::vector<float>  vec(3, 1.000000);
    ft::vector<float>  vec_2(vec.begin(), vec.end());
    std::cout << "Capacity custom count allocator constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Size custom count allocator constructor : " << vec_2.size() << std::endl;
    for (ft::vector<float>::iterator	it = vec_2.begin(); it != vec_2.end(); it++)
		std::cout << *it << std::endl;
}

void    copy_custom_constructor()
{
    std::cout << "Copy custom constructor" << std::endl;
    ft::vector<float>  vec(3, 1.000000);
    ft::vector<float>  vec_2(vec.begin(), vec.end());
    ft::vector<float>  vec_cpy(vec_2);
    for (ft::vector<float>::iterator	it = vec_cpy.begin(); it != vec_cpy.end(); it++)
		std::cout << *it << std::endl;
}