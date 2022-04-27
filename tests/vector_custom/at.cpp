#include "at.hpp"

void    at_custom_ok()
{
    ft::vector<int>vec;

    vec.assign(2, 1);
    std::cout << "at(1) " << vec.at(1) << std::endl;
    std::cout << "at(0) " << vec.at(0) << std::endl;
    std::cout << "[1] " << vec[1] << std::endl;
    std::cout << "[0] " << vec[0] << std::endl;
    try
    {
        vec.at(2);
    }
    catch(std::out_of_range const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    at_custom_const_ok()
{
    std::cout << "AT_CUSTOM_CONST" << std::endl;
    ft::vector<int>vec;
    vec.assign(2, 1);
    const ft::vector<int>vec_const(vec);
    std::cout << "at(1) " << vec_const.at(1) << std::endl;
    std::cout << "at(0) " << vec_const.at(0) << std::endl;
    std::cout << "[1] " << vec_const[1] << std::endl;
    std::cout << "[0] " << vec_const[0] << std::endl;
}

void    at_custom_out_of_range()
{
    ft::vector<int>vec;

    try
    {
        vec.at(-1);
    }
    catch(std::out_of_range const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    for (int i = 0; i < 2; i++)
    {
        try
        {
            vec.at(i);
        }
        catch(std::out_of_range const& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}