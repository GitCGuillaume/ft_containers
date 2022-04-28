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