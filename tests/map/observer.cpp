#include "observer.hpp"

void    test_keycomp()
{
    std::cout << "Test KeyComp" << std::endl;
    TYPECONT::map<int, int>   map;
    TYPECONT::map<int, int, struct s_cmp<int> >   map_2;
    TYPECONT::less<int>  comp = map.key_comp();
    struct s_cmp<int>  comp2 = map_2.key_comp();
    map.insert(TYPECONT::make_pair(2, 12));
    map.insert(TYPECONT::make_pair(3, -1));
    map.insert(TYPECONT::make_pair(4, 145));
    map.insert(TYPECONT::make_pair(0, 145));
    TYPECONT::map<int, int>::iterator it = map.begin();
    for (int i = 1; i < 4; i++, it++)
    {
        std::cout << "comp result (<) : " << comp(2, it->first) << std::endl;
        std::cout << "comp2 result (>) : " << comp2(it->first, 2) << std::endl;
    }
}

void    test_value_comp()
{
    std::cout << "Test Value Comp" << std::endl;
    TYPECONT::map<int, int>   map;
    TYPECONT::map<int, int, struct s_cmp<int> >   map_2;
    TYPECONT::map<int, int>::value_compare  comp = map.value_comp();
    TYPECONT::map<int, int, struct s_cmp<int> >::value_compare  comp2 = map_2.value_comp();
    map.insert(TYPECONT::make_pair(2, 12));
    map.insert(TYPECONT::make_pair(3, -1));
    map.insert(TYPECONT::make_pair(4, 145));
    map.insert(TYPECONT::make_pair(0, 145));
    TYPECONT::map<int, int>::iterator it = map.begin();
    TYPECONT::pair<int, int> pair(2, 2);
    for (int i = 1; i < 4; i++, it++)
    {
        std::cout << "comp result (<) : " << comp(pair, TYPECONT::make_pair(i, 1)) << std::endl;
        std::cout << "comp2 result (>) : " << comp2(TYPECONT::make_pair(i, 1), pair) << std::endl;
    }
}