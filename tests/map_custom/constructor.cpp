#include "constructor.hpp"

void    default_constructor_map_custom()
{
  std::cout << "Default constructor Map CUSTOM" << std::endl;
  ft::map<std::string, int> map;
  const ft::map<std::string, int> const_map;

  std::cout << "CRASH SI JE it->first" << std::endl;
  std::cout << "it TEST : " << map.begin()->first << std::endl;
  std::cout << "Size default constructor : " << map.size() << std::endl;
  std::cout << "Size default const constructor : " << const_map.size() << std::endl;
  //ft::map<std::string, int> map_alloc(map.key_comp(), map.get_allocator());
}

void    constructor_range_map_custom()
{
  std::cout << "constructor range (1) Map CUSTOM" << std::endl;
  ft::map<std::string, int> map;
  map["abc"] = -2147483647;
  map["jkl"] = 2147483648;
  map["ghi"] = 0;
  map["mno"] = 54644587;
  map["ghi"] = 1;
  map["def"] = 21354;
  map["m"] = 1;
  map["pqr"] = 1;
  map["stu"] = 2145;
  ft::map<std::string, int>::iterator it = map.begin();
  //it++;
  //it++;
  //map.insert(/*it, */std::make_pair("m", 123));
  ft::map<std::string, int> map_arr(map.begin(), map.end());
 // exit(0);
  //std::cout << "Size map constructor : " << map.size() << std::endl;
  //std::cout << "Size map_arr constructor : " << map_arr.size() << std::endl;
  for (ft::map<std::string, int>::iterator	it = map_arr.begin(); it != map_arr.end(); it++)
		std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
  for (ft::map<std::string, int>::iterator	it = map_arr.begin(); it != map_arr.end(); it++)
		std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
  ft::map<std::string, int>::iterator it2 = map_arr.begin();
  ft::map<std::string, int>::iterator ite = map_arr.end();
  it2--;
  ite--;
  for (; ite != it2; ite--)
    std::cout << "arr end : " << ite->first << std::endl;
  it2 = map_arr.begin();
  ite = map_arr.end();
  it2--;
  ite--;
  for (; ite != it2; ite--)
    std::cout << "arr end : " << ite->first << std::endl;
  for (ft::map<std::string, int>::iterator	it = map.begin(); it != map.end(); it++)
		std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    copy_constructor_map_custom()
{
  std::cout << "Copy constructor CUSTOM" << std::endl;
  ft::map<std::string, float> map;
  map["abc"] = -2147483647;
  map["def"] = 2147483648;
  map["ghi"] = 0;
  map["jkl"] = 21354;
  map["mno"] = 54644587;
   map["m"] = 54644587;
  ft::map<std::string, float>  map_cpy(map);
  //std::cout << "Capacity count COPY constructor : " << map_cpy.capacity() << std::endl;
  std::cout << "Size count COPY constructor : " << map_cpy.size() << std::endl;
  for (ft::map<std::string, float>::iterator	it = map_cpy.begin(); it != map_cpy.end(); it++)
    std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    operator_assignation_map_custom()
{
    std::cout << "Operator assignation map CUSTOM" << std::endl;
    ft::map<std::string, int> map1;
    ft::map<std::string, int> map2;

    map1["abc"] = -2147483647;
    map1["def"] = 2147483648;
    map1["ghi"] = 0;
    map1["jkl"] = 21354;
    map1["mno"] = 54644587;
    map1["m"] = 54644587;
    map2 = map1;
    for (ft::map<std::string, int>::iterator	it = map2.begin(); it != map2.end(); it++)
		  std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
    std::cout << "ASSIGNATION SIZE : " << map2.size() << std::endl;
    std::cout << "Assignation from EMPTY MAP" << std::endl;
    ft::map<std::string, int> map3;
    map1 = map3;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << map1.size() << std::endl;
    for (ft::map<std::string, int>::iterator	it = map1.begin(); it != map1.end(); it++)
		  std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void  assignation_speed_custom()
{
  std::cout << "Assignation copy speed CUSTOM" << std::endl;
  ft::map<double, double> map;
  ft::map<double, double>  map2;

  for (double i = 0; i < 100000; i++)
    map[i] = i;
  map.insert(map.find(1), ft::make_pair(30000000, 123));
  map.insert(map.find(50000), ft::make_pair(10000000, 123));
  map.insert(map.find(98000), ft::make_pair(20000000, 123));
  map2 = map;
  ft::map<double, double>::iterator  it = map2.end();
  static_cast<void>(it);
}

void  constructor_range_speed_custom()
{
  std::cout << "Constructor range speed CUSTOM" << std::endl;
  ft::map<double, double> map;

  for (double i = 0; i < 100000; i++)
    map[i] = i;
  map.insert(map.find(1), ft::make_pair(30000000, 123));
  map.insert(map.find(50000), ft::make_pair(10000000, 123));
  map.insert(map.find(98000), ft::make_pair(20000000, 123));
  ft::map<double, double> map2(map.begin(), map.end());
  ft::map<double, double>::iterator  it = map2.end();
}

void  constructor_copy_speed_custom()
{
  std::cout << "Constructor COPY range speed CUSTOM" << std::endl;
  ft::map<double, double> map;

  for (double i = 0; i < 40000; i++)
    map[i] = i;
  ft::map<double, double> map2(map);
}
/*
void  destructor_1()
{
  ft::map<int, int> map_1;
  map_1[1] = 1;
  map_1[2] = 2;
  ft::map<int, int> map_2;
  map_2[1] = 1;
  map_2[2] = 2;
  map_2[3] = 3;
  ft::map<int, int> map_3;
  map_3[1] = 1;
  map_3[2] = 2;
  map_3[3] = 3;
  map_3[4] = 4;
  ft::map<int, int> map_4;
  map_4[1] = 1;
  map_4[2] = 2;
  map_4[3] = 3;
  map_4[4] = 4;
  map_4[5] = 5;
  map_4[6] = 6;
  map_4[7] = 7;
  map_4[8] = 8;
  
  map_4[9] = 9;
  map_4[10] = 10;
  map_4[11] = 11;
  map_4[12] = 12;
  map_4[13] = 13;
}

void  destructor_right_emplacement()
{
  ft::map<int, int> map_4;
  map_4[1] = 1;
  map_4[2] = 2;
  map_4[3] = 3;
  map_4[4] = 4;
  map_4[5] = 5;
  map_4[6] = 6;
  map_4[7] = 7;
  map_4[8] = 8;
  
  map_4[9] = 9;
  map_4[10] = 10;
  map_4[11] = 11;
  map_4[12] = 12;
  map_4[13] = 13;
  map_4[14] = 14;
  map_4[15] = 15;
}*/