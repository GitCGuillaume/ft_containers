#include "constructor.hpp"

void    default_constructor()
{
    std::vector<int> vec;
    const std::vector<int> const_vec;

    std::cout << "Default constructor" << std::endl;
    std::cout << "Capacity default constructor : " << vec.capacity() << std::endl;
    std::cout << "Size default constructor : " << vec.size() << std::endl;
    std::cout << "Capacity default const constructor : " << const_vec.capacity() << std::endl;
    std::cout << "Size default const constructor : " << const_vec.size() << std::endl;
    std::cout << "max size : " << vec.max_size() << std::endl;
    std::cout << "max size const: " << const_vec.max_size() << std::endl;
}

void    allocator_constructor()
{
    std::cout << "ALLOCATOR CONSTRUCTOR" << std::endl;
    std::vector<int> vec;

    std::cout << "Allocator vec.get_allocator()" << std::endl;
    vec.assign(5, 1);
    std::vector<int> vec_alloc(vec.get_allocator());
    std::cout << "Capacity allocator constructor : " << vec_alloc.capacity() << std::endl;
    std::cout << "Size allocator constructor : " << vec_alloc.size() << std::endl;
}

void    allocator_count_constructor()
{
    std::cout << "Allocator count constructor" << std::endl;

    std::vector<std::string> vec(3, "str value");
    std::cout << "Capacity count allocator constructor : " << vec.capacity() << std::endl;
    std::cout << "Size count allocator constructor : " << vec.size() << std::endl;
	for (std::vector<std::string>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

void    allocator_iterator()
{
    std::cout << "Allocator iterator constructor" << std::endl;
    std::vector<float>  vec(3, 1.000000);
    std::vector<float>  vec_2(vec.begin(), vec.end());
    std::cout << "Capacity count allocator constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Size count allocator constructor : " << vec_2.size() << std::endl;
    for (std::vector<float>::iterator	it = vec_2.begin(); it != vec_2.end(); it++)
		std::cout << *it << std::endl;
}

void    copy_constructor()
{
    std::cout << "Copy constructor" << std::endl;
    std::vector<float>  vec_speed(30000, 1.000000);
    std::vector<float>  vec_2_speed(vec_speed.begin(), vec_speed.end());
    std::vector<float>  vec_cpy_speed(vec_2_speed);

    std::vector<float>  vec(3, 1.000000);
    std::vector<float>  vec_2(vec.begin(), vec.end());
    std::vector<float>  vec_cpy(vec_2);
    std::cout << "Capacity count COPY constructor : " << vec_cpy.capacity() << std::endl;
    std::cout << "Size count COPY constructor : " << vec_cpy.size() << std::endl;
    for (std::vector<float>::iterator	it = vec_cpy.begin(); it != vec_cpy.end(); it++)
		std::cout << *it << std::endl;
}

void    operator_assignation_constructor()
{
    std::cout << "Constructor assignation" << std::endl;
    std::vector<int> vec;
    std::vector<int> vec2;

    vec.assign(5, 1);
    vec2 = vec;
    std::cout << "Capacity count ASSIGNATION constructor : " << vec2.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor : " << vec2.size() << std::endl;
    for (std::vector<int>::iterator	it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
    std::cout << "Constructor assignation test assignation from EMPTY" << std::endl;
    std::vector<int> vec3(10, 42);
    std::vector<int> vec4;
    vec3 = vec4;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY : " << vec3.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << vec3.size() << std::endl;
    for (std::vector<int>::iterator	it = vec3.begin(); it != vec3.end(); it++)
		  std::cout << *it << std::endl;
    vec3.resize(50, 1);
    vec4 = vec3;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY : " << vec3.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << vec3.size() << std::endl;
    std::cout << "Capacity count ASSIGNATION constructor EMPTY : " << vec4.capacity() << std::endl;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << vec4.size() << std::endl;
    std::vector<int> vec5;
    std::vector<int> vec6;
    vec5.push_back(1);
    vec5.push_back(2);
    vec5.push_back(3);
    vec6 = vec5;
}

void    fill_constructor()
{
    std::cout << "Fill constructor" << std::endl;

    std::vector<int>    vec(5);
    std::cout << "Capacity count FILL constructor : " << vec.capacity() << std::endl;
    std::cout << "Size count FILL constructor : " << vec.size() << std::endl;
    for (std::vector<int>::iterator	it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}