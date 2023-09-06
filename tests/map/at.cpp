#include "at.hpp"

void    at_map()
{
    NAMESPACE::map<std::string, std::string>   map;

    map["un"] = "value_un";
    std::cout << "at : " << map.at("un") << std::endl;
    const NAMESPACE::map<std::string, std::string>   map2(map.begin(), map.end());
    std::cout << "at : " << map.at("un") << std::endl;
    try{
        map.at("");
    }
    catch (std::exception& e)
    {
        std::cout << "error : " << e.what() << std::endl;
    }
}