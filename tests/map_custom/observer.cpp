#include "observer.hpp"

template<typename T>
struct  s_cmp
{
    bool    operator()(T const & lhs, T const & rhs) const
    {
        return (lhs > rhs);
    }
};

void    test_keycomp_custom()
{
    std::cout << "Test KeyComp CUSTOM" << std::endl;
    ft::map<int, int>   map;
    ft::map<int, int, struct s_cmp<int> >   map2;
    ft::less<int>  comp = map.key_comp();
    struct s_cmp<int>  comp2 = map2.key_comp();
    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    map.insert(ft::make_pair(0, 145));
    ft::map<int, int>::iterator it = map.begin();
    for (int i = 1; i < 4; i++, it++)
    {
        std::cout << "comp result (<) : " << comp(2, it->first) << std::endl;
        std::cout << "comp2 result (>) : " << comp2(it->first, 2) << std::endl;
    }
}

void    test_value_comp_custom()
{
    std::cout << "Test Value Comp CUSTOM" << std::endl;
    ft::map<int, int>   map;
    ft::map<int, int, struct s_cmp<int> >   map2;
    ft::map<int, int>::value_compare  comp = map.value_comp();
    ft::map<int, int, struct s_cmp<int> >::value_compare  comp2 = map2.value_comp();
    map.insert(ft::make_pair(2, 12));
    map.insert(ft::make_pair(3, -1));
    map.insert(ft::make_pair(4, 145));
    map.insert(ft::make_pair(0, 145));
    ft::map<int, int>::iterator it = map.begin();
    ft::pair<int, int> pair(2, 2);
    for (int i = 1; i < 4; i++, it++)
    {
        std::cout << "comp result (<) : " << comp(pair, ft::make_pair(i, 1)) << std::endl;
        std::cout << "comp2 result (>) : " << comp2(ft::make_pair(i, 1), pair) << std::endl;
    }
}