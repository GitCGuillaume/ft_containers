#include "iterator.hpp"

void    iterator_map_default_custom()
{
    std::cout << "MAP ITERATOR DEFAULT CUSTOM" << std::endl;
    ft::map<int, int>  map;
    ft::map<int, int>::iterator  it = map.begin();
    ft::map<int, int>::iterator  ite = map.end();
    if (it != ite)
    {
        std::cout << "first : " << it->first << std::endl;
        std::cout << "second : " << it->second << std::endl;
    }
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
    std::cout << "Iterator forward map CUSTOM" << std::endl;
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

void    iterator_backward_map_custom()
{
    std::cout << "Iterator backward map CUSTOM" << std::endl;
    ft::map<int, int>  map;
    map[3] = 1;
    map[4] = 2;
    map[0] = 3;
    map[1] = 4;
    ft::map<int, int>::const_iterator    it = map.end();
    it--;
    std::cout << "it->first : " << it->first << std::endl;
    std::cout << "it->second : " << it->second << std::endl;
    std::cout << "(it--)->first : " << (it--)->first << std::endl;
    std::cout << "(it--)->first : " << (it--)->first << std::endl;
    std::cout << "(it--)->first : " << (it--)->first << std::endl;
    std::cout << "(it--)->first : " << (it--)->first << std::endl;
    it = map.end();
    it--;
    std::cout << "(it--)->second : " << (it--)->second << std::endl;
    std::cout << "(it--)->second : " << (it--)->second << std::endl;
    std::cout << "(it--)->second : " << (it--)->second << std::endl;
    std::cout << "(it--)->second : " << (it--)->second << std::endl;
    it = map.end();
    std::cout << "(--it)->first : " << (--it)->first << std::endl;
    std::cout << "(--it)->first : " << (--it)->first << std::endl;
    std::cout << "(--it)->first : " << (--it)->first << std::endl;
    std::cout << "(--it)->first : " << (--it)->first << std::endl;
    it = map.end();
    std::cout << "(--it)->second : " << (--it)->second << std::endl;
    std::cout << "(--it)->second : " << (--it)->second << std::endl;
    std::cout << "(--it)->second : " << (--it)->second << std::endl;
    std::cout << "(--it)->second : " << (--it)->second << std::endl;
}

void    reverse_iterator_map_custom()
{
    std::cout << "Reverse iterator MAP CUSTOM" << std::endl;
    ft::map<int, int>    map;
	ft::map<int, int>::reverse_iterator it(map.rbegin());
	ft::map<int, int>::const_reverse_iterator ite(map.rend());

	it = map.rbegin();
	ite = map.rbegin();
    static_cast<void>(it);
    static_cast<void>(ite);
    for (int i = 1; i < 6; i++)
        map.insert(ft::make_pair(i, i));
    for (ft::map<int, int>::reverse_iterator rit = map.rbegin(); rit != map.rend(); rit++)
        std::cout << (*rit).first << std::endl;
    for (ft::map<int, int>::reverse_iterator rit = --map.rend(); rit != map.rbegin(); rit--)
       std::cout << (*rit).first << std::endl;
    for (ft::map<int, int>::reverse_iterator rit = --map.rend(); rit != map.rbegin(); rit--)
        std::cout << (*rit).first << std::endl;
}

void    reverse_iterator_empty_map_custom()
{
    std::cout << "Reverse iterator empty MAP CUSTOM" << std::endl;
    ft::map<int, int>    map;

    for (ft::map<int, int>::reverse_iterator rit = map.rbegin(); rit != map.rend(); rit++)
        std::cout << (*rit).first << std::endl;
}