#include "at.hpp"

void    at_ok()
{
    std::vector<int>vec;

    vec.assign(2, 1);
    std::cout << "at(1) " << vec.at(1) << std::endl;
    std::cout << "at(0) " << vec.at(0) << std::endl;
}

void    at_out_of_range()
{
    std::vector<int>vec;

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