#include "iterator.hpp"

void    iterator_map_default_custom()
{
    std::cout << "MAP ITERATOR DEFAULT CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator  it = map.begin();
    std::cout << "first : " << it->first << std::endl;
    std::cout << "second : " << it->second << std::endl;
}

void    iterator_assignation_map_custom()
{
    std::cout << "Iterator assignation MAP CUSTOM" << std::endl;
    ft::map<std::string, std::string>  map;
    map["un"] = "value un";
    ft::map<std::string, std::string>::iterator it = map.begin();
    ft::map<std::string, std::string>::iterator it_cpy = it;
    std::cout << "it->first : " << it->first << std::endl;
    std::cout << "it_cpy->first : " << it_cpy->first << std::endl;
    std::cout << "it->second : " << it->second << std::endl;
    std::cout << "it_cpy->second : " << it_cpy->second << std::endl;
}

void    iterator_forward_map_custom()
{
    std::cout << "Iterator forward map" << std::endl;
    ft::map<int, int>  map;
    map[3] = 1;
    map[4] = 2;
    map[0] = 3;
    map[1] = 4;
    ft::map<int, int>::iterator    it = map.begin();
    std::cout << "it->first : " << it->first << std::endl;
    std::cout << "it->second : " << it->second << std::endl;
    std::cout << "(it++)->first : " << (it++)->first << std::endl;
    std::cout << "(it++)->first : " << (it++)->first << std::endl;
    std::cout << "(it++)->first : " << (it++)->first << std::endl;
    std::cout << "(it++)->first : " << (it++)->first << std::endl;
    it = map.begin();
    std::cout << "(it++)->second : " << (it++)->second << std::endl;
    std::cout << "(it++)->second : " << (it++)->second << std::endl;
    std::cout << "(it++)->second : " << (it++)->second << std::endl;
    std::cout << "(it++)->second : " << (it++)->second << std::endl;
    it = map.begin();
    std::cout << "(++it)->first : " << (++it)->first << std::endl;
    std::cout << "(++it)->first : " << (++it)->first << std::endl;
    std::cout << "(++it)->first : " << (++it)->first << std::endl;
    it = map.begin();
    std::cout << "(++it)->second : " << (++it)->second << std::endl;
    std::cout << "(++it)->second : " << (++it)->second << std::endl;
    std::cout << "(++it)->second : " << (++it)->second << std::endl;
}