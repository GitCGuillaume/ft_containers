#include "front_back.hpp"

void    front()
{
    std::cout << "FRONT VECTOR : " << std::endl;
    TYPECONT::vector<int>   vec;
    vec.assign(2, 1);
    const   TYPECONT::vector<int>   vec_cpy(vec);
    std::cout << "front : " << vec.front() << std::endl;
    std::cout << "front : " << vec_cpy.front() << std::endl;
}

void    back()
{
    std::cout << "BACK VECTOR : " << std::endl;
    TYPECONT::vector<int>   vec;
    vec.assign(2, 1);
    const   TYPECONT::vector<int>   vec_cpy(vec);
    std::cout << "back : " << vec.back() << std::endl;
    std::cout << "back : " << vec_cpy.back() << std::endl;
}