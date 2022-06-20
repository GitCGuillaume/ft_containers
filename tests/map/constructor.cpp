#include "constructor.hpp"

void    default_constructor_map()
{
  std::cout << "Default constructor Map" << std::endl;
  TYPECONT::map<std::string, int> map;
  const TYPECONT::map<std::string, int> const_map;

  std::cout << "Size default constructor : " << map.size() << std::endl;
  std::cout << "Size default const constructor : " << const_map.size() << std::endl;
  std::cout << "max_size : " << const_map.max_size() << std::endl;
  TYPECONT::map<std::string, int> map_alloc(map.key_comp(), map.get_allocator());
}

void    constructor_range_map()
{
  std::cout << "constructor range (1) Map" << std::endl;
  TYPECONT::map<std::string, int> map;
  map["abc"] = -2147483647;
  map["jkl"] = -2147483648;
  map["ghi"] = 0;
  map["mno"] = 54644587;
  map["ghi"] = 1;
  map["def"] = 21354;
  map["m"] = 1;
  map["pqr"] = 1;
  map["stu"] = 2145;
  map.insert(TYPECONT::make_pair("m", 123));
  TYPECONT::map<std::string, int> map_arr(map.begin(), map.end());
  std::cout << "Size map constructor : " << map.size() << std::endl;
  std::cout << "Size map_arr constructor : " << map_arr.size() << std::endl;
  for (TYPECONT::map<std::string, int>::iterator	it = map_arr.begin(); it != map_arr.end(); it++)
		std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
  
  TYPECONT::map<std::string, int>::iterator it_2 = map_arr.begin();
  TYPECONT::map<std::string, int>::iterator ite = map_arr.end();
  it_2--;
  ite--;
  for (; ite != it_2; ite--)
    std::cout << "arr end : " << ite->first << std::endl;
  it_2 = map_arr.begin();
  ite = map_arr.end();
  it_2--;
  ite--;
  for (; ite != it_2; ite--)
    std::cout << "arr end : " << ite->first << std::endl;
}

void    copy_constructor_map()
{
  std::cout << "Copy constructor" << std::endl;
  TYPECONT::map<std::string, float> map;
  map["abc"] = -2147483647.0;
  map["def"] = -2147483648.0;
  map["ghi"] = 0;
  map["jkl"] = 21354.0;
  map["mno"] = 54644587.0;
   map["m"] = 54644587.0;
  TYPECONT::map<std::string, float>  map_cpy(map);
  //std::cout << "Capacity count COPY constructor : " << map_cpy.capacity() << std::endl;
  std::cout << "Size count COPY constructor : " << map_cpy.size() << std::endl;
  for (TYPECONT::map<std::string, float>::iterator	it = map_cpy.begin(); it != map_cpy.end(); it++)
    std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void    operator_assignation_map()
{
    std::cout << "Operator assignation map" << std::endl;
    TYPECONT::map<std::string, int> map_1;
    TYPECONT::map<std::string, int> map_2;

    map_1["abc"] = -2147483647;
    map_1["def"] = -2147483648;
    map_1["ghi"] = 0;
    map_1["jkl"] = 21354;
    map_1["mno"] = 54644587;
    map_1["m"] = 54644587;
    map_2 = map_1;
    for (TYPECONT::map<std::string, int>::iterator	it = map_2.begin(); it != map_2.end(); it++)
		  std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
    std::cout << "ASSIGNATION SIZE : " << map_2.size() << std::endl;
    std::cout << "Assignation from EMPTY MAP" << std::endl;
    TYPECONT::map<std::string, int> map3;
    map_1 = map3;
    std::cout << "Size count ASSIGNATION constructor EMPTY : " << map_1.size() << std::endl;
    for (TYPECONT::map<std::string, int>::iterator	it = map_1.begin(); it != map_1.end(); it++)
		  std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;
}

void  assignation_speed()
{
  std::cout << "Assignation copy speed" << std::endl;
  TYPECONT::map<double, double> map;
  TYPECONT::map<double, double> map_2;
  for (double i = 0; i < 100000; i++)
    map[i] = i;
  map.insert(map.find(1), TYPECONT::make_pair(30000000, 123));
  map.insert(map.find(50000), TYPECONT::make_pair(10000000, 123));
  map.insert(map.find(98000), TYPECONT::make_pair(20000000, 123));
  map_2 = map;
  TYPECONT::map<double, double>::iterator  it = map_2.end();
  static_cast<void>(it);
}

void  constructor_range_speed()
{
  std::cout << "Constructor range speed" << std::endl;
  TYPECONT::map<double, double> map;

  for (double i = 0; i < 100000; i++)
    map.insert(TYPECONT::make_pair(i - 1, i));
  map.insert(map.find(1), TYPECONT::make_pair(30000000, 123));
  map.insert(map.find(50000), TYPECONT::make_pair(10000000, 123));
  map.insert(map.find(98000), TYPECONT::make_pair(20000000, 123));
  TYPECONT::map<double, double> map_2(map.begin(), map.end());
  TYPECONT::map<double, double>::iterator  it = map_2.end();
  static_cast<void>(it);
}

void  constructor_copy_speed()
{
  std::cout << "Constructor COPY range speed" << std::endl;
  TYPECONT::map<double, double> map;

  for (double i = 0; i < 40000; i++)
    map[i] = i;
  TYPECONT::map<double, double> map_2(map);
}
