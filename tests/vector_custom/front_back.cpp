#include "front_back.hpp"

void    front_custom()
{
    std::cout << "FRONT CUSTOM VECTOR : " << std::endl;
    ft::vector<int>vec;
    vec.assign(2, 1);
    const   ft::vector<int>vec_cpy(vec);
    std::cout << "front : " << vec.front() << std::endl;
    std::cout << "front : " << vec_cpy.front() << std::endl;
}

void    back_custom()
{
    std::cout << "BACK CUSTOM VECTOR : " << std::endl;
    ft::vector<int>vec;
    vec.assign(2, 1);
    const   ft::vector<int>vec_cpy(vec);
    std::cout << "back : " << vec.back() << std::endl;
    std::cout << "back : " << vec_cpy.back() << std::endl;
}