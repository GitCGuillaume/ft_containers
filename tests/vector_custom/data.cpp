#include "data.hpp"

void    test_custom_data()
{
    std::cout << "Test custom data()" << std::endl;
    ft::vector<int>    vec;

    vec.assign(2, 1);
    std::cout << vec.data()[0] << " " << vec.data()[1] << std::endl;
}

void    test_custom_const_data()
{
    std::cout << "Test const custom data()" << std::endl;
    const ft::vector<int>    vec(2, 1);

    std::cout << vec.data()[0] << " " << vec.data()[1] << std::endl;
}