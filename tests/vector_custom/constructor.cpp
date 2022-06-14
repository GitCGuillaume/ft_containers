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
    std::cout << "max size : " << vec.max_size() << std::endl;
    std::cout << "max size const: " << const_vec.max_size() << std::endl;
}

void    allocator_custom_constructor()
{
    std::cout << "ALLOCATOR CUSTOM CONSTRUCTOR" << std::endl;
    ft::vector<int> vec;

    std::cout << "Allocator custom vec.get_allocator()" << std::endl;
    vec.assign(5, 1);
    ft::vector<int> vec_alloc(vec.get_allocator());
    std::cout << "Capacity custom allocator constructor : " << vec_alloc.capacity() << std::endl;
    std::cout << "Size custom allocator constructor : " << vec_alloc.size() << std::endl;
}

void    allocator_custom_count_constructor()
{
    std::cout << "Allocator count constructor CUSTOM" << std::endl;

	ft::vector<std::string> vec(3, "str value");
    std::cout << "Capacity custom count allocator constructor : " << vec.capacity() << std::endl;
    std::cout << "Size custom count allocator constructor : " << vec.size() << std::endl;
    for (ft::vector<std::string>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

void    allocator_custom_iterator()
{
    std::cout << "Allocator iterator constructor CUSTOM" << std::endl;

    ft::vector<float>  vec(3, 1.000000);
    ft::vector<float>  vec_2(vec.begin(), vec.end());
    std::cout << "Capacity custom count allocator constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Size custom count allocator constructor : " << vec_2.size() << std::endl;
    for (ft::vector<float>::iterator	it = vec_2.begin(); it != vec_2.end(); it++)
		std::cout << *it << std::endl;
}

void    copy_custom_constructor()
{
    std::cout << "Copy custom constructor CUSTOM" << std::endl;
    ft::vector<float>  vec(3, 1.000000);
    ft::vector<float>  vec_2(vec.begin(), vec.end());
    ft::vector<float>  vec_cpy(vec_2);
    std::cout << "Capacity count COPY constructor : " << vec_cpy.capacity() << std::endl;
    std::cout << "Size count COPY constructor : " << vec_cpy.size() << std::endl;
    for (ft::vector<float>::iterator	it = vec_cpy.begin(); it != vec_cpy.end(); it++)
		std::cout << *it << std::endl;
}

void    operator_custom_assignation_constructor()
{
    std::cout << "Constructor custom assignation CUSTOM" << std::endl;
    ft::vector<int> vec;
    ft::vector<int> vec2;

    vec.assign(5, 1);
    vec2 = vec;
    std::cout << "Capacity count ASSIGNATION constructor CUSTOM : " << vec2.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor CUSTOM : " << vec2.size() << std::endl;
    for (ft::vector<int>::iterator	it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
    std::cout << "Constructor assignation test assignation from EMPTY CUSTOM" << std::endl;
    ft::vector<int> vec3(10, 42);
    ft::vector<int> vec4;
    vec3 = vec4;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY CUSTOM : " << vec3.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY CUSTOM : " << vec3.size() << std::endl;
    for (ft::vector<int>::iterator	it = vec3.begin(); it != vec3.end(); it++)
		  std::cout << *it << std::endl;
        vec3.resize(50, 1);
    vec4 = vec3;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY : " << vec3.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << vec3.size() << std::endl;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY : " << vec4.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << vec4.size() << std::endl;
    ft::vector<int> vec3;
    ft::vector<int> vec4;
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);
    vec4 = vec3;
}

void    fill_constructor_custom()
{
    std::cout << "Fill constructor CUSTOM" << std::endl;

    ft::vector<int>    vec(5);
    std::cout << "Capacity count FILL constructor custom : " << vec.capacity() << std::endl;
    std::cout << "Size count FILL constructor custom : " << vec.size() << std::endl;
    for (ft::vector<int>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}