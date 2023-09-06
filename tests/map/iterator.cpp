#include "iterator.hpp"

void    iterator_map_default()
{
    std::cout << "MAP ITERATOR DEFAULT" << std::endl;
    NAMESPACE::map<int, int>  map;
    NAMESPACE::map<int, int>::iterator  it = map.begin();
    NAMESPACE::map<int, int>::iterator  ite = map.end();
    if (it != ite)
    {
        std::cout << "first : " << it->first << std::endl;
        std::cout << "second : " << it->second << std::endl;
    }
}

void    iterator_assignation_map()
{
    std::cout << "Iterator assignation MAP" << std::endl;
    NAMESPACE::map<std::string, std::string>  map;
    map["un"] = "value un";
    NAMESPACE::map<std::string, std::string>::iterator it = map.begin();
    NAMESPACE::map<std::string, std::string>::iterator it_cpy = it;
    std::cout << "it->first : " << it->first << std::endl;
    std::cout << "it_cpy->first : " << it_cpy->first << std::endl;
    std::cout << "it->second : " << it->second << std::endl;
    std::cout << "it_cpy->second : " << it_cpy->second << std::endl;
}

void    iterator_forward_map()
{
    std::cout << "Iterator forward map" << std::endl;
    NAMESPACE::map<int, int>  map;
    map[3] = 1;
    map[4] = 2;
    map[0] = 3;
    map[1] = 4;
    NAMESPACE::map<int, int>::iterator    it = map.begin();
    NAMESPACE::map<int, int>::iterator    cit = map.begin();
    if (it == cit)
    {
        std::cout << "COMPARE SAME = ( it->first: " << it->first << " it->second: " << it->second << " )"
            << std::endl << "COMPARE CIT SAME = cit->first: "
            << cit->first << " cit->second: " << cit->second << " )" << std::endl;
    }
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

void    iterator_backward_map()
{
    std::cout << "Iterator backward map" << std::endl;
    NAMESPACE::map<int, int>  map;
    map[3] = 1;
    map[4] = 2;
    map[0] = 3;
    map[1] = 4;
    NAMESPACE::map<int, int>::const_iterator    it = map.end();
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

void    reverse_iterator_map()
{
    std::cout << "Reverse iterator MAP" << std::endl;
    NAMESPACE::map<int, int>    map;
	NAMESPACE::map<int, int>::reverse_iterator it(map.rbegin());
	NAMESPACE::map<int, int>::const_reverse_iterator ite(map.rend());

	it = map.rbegin();
	ite = map.rbegin();
    static_cast<void>(it);
    static_cast<void>(ite);
    for (int i = 1; i < 6; i++)
        map.insert(NAMESPACE::make_pair(i, i));
    for (NAMESPACE::map<int, int>::reverse_iterator rit = map.rbegin(); rit != map.rend(); rit++)
        std::cout << (*rit).first << std::endl;
    for (NAMESPACE::map<int, int>::reverse_iterator rit = --map.rend(); rit != map.rbegin(); rit--)
       std::cout << (*rit).first << std::endl;
    for (NAMESPACE::map<int, int>::reverse_iterator rit = --map.rend(); rit != map.rbegin(); rit--)
        std::cout << (*rit).first << std::endl;
}

void    reverse_iterator_empty_map()
{
    std::cout << "Reverse iterator empty MAP" << std::endl;
    NAMESPACE::map<int, int>    map;

    for (NAMESPACE::map<int, int>::reverse_iterator rit = map.rbegin(); rit != map.rend(); rit++)
        std::cout << (*rit).first << std::endl;
}