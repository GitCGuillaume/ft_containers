#include "modifiers.hpp"

void    clear_custom()
{
    std::cout << "Clear custom, no values be displayed below." << std::endl;
    ft::vector<std::string>    vec(5, "test");

    vec.clear();
    for (ft::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}