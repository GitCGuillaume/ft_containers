#include "data.hpp"

void    test_data()
{
    std::cout << "Test data()" << std::endl;
    NAMESPACE::vector<int>    vec;

    vec.assign(2, 1);
    std::cout << vec.data()[0] << " " << vec.data()[1] << std::endl;
}

void    test_const_data()
{
    std::cout << "Test const data()" << std::endl;
    const NAMESPACE::vector<int>    vec(2, 1);

    std::cout << vec.data()[0] << " " << vec.data()[1] << std::endl;
}