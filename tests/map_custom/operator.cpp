#include "operator.hpp"

void    equal_map_custom()
{
    std::cout << "Operator MAP CUSTOM" << std::endl;
    ft::map<std::string, int>    map_1;
    ft::map<std::string, int>    map_2;
    ft::map<std::string, int>    map_3;
    ft::map<std::string, int>    map_4;

    map_1["one"] = 1;
    map_1["two"] = 2;
    map_1["three"] = 3;
    map_2["four"] = 4;
    map_2["five"] = 5;
    map_3["one"] = 1;
    map_3["two"] = 2;
    map_3["three"] = 3;
    map_4["four"] = 4;
    map_4["five"] = 5;
    map_4["six"] = 3;
    std::cout << "==" << std::endl;
    std::cout << (map_1["one"] == map_2["two"]) << std::endl;
    std::cout << (map_2["two"] == map_1["one"]) << std::endl;
    std::cout << (map_1["one"] == map_3["three"]) << std::endl;
    std::cout << (map_1["one"] == map_4["four"]) << std::endl;
    std::cout << "!=" << std::endl;
    std::cout << (map_1["one"] != map_2["two"]) << std::endl;
    std::cout << (map_2["two"] != map_1["one"]) << std::endl;
    std::cout << (map_1["one"] != map_3["three"]) << std::endl;
    std::cout << (map_1["one"] != map_4["four"]) << std::endl;
    std::cout << "<" << std::endl;
    std::cout << (map_1["one"] < map_2["two"]) << std::endl;
    std::cout << (map_1["one"] < map_3["three"]) << std::endl;
    std::cout << (map_2["two"] < map_1["one"]) << std::endl;
    std::cout << (map_1["one"] < map_4["four"]) << std::endl;
    std::cout << (map_4["four"] < map_1["one"]) << std::endl;
    std::cout << "<=" << std::endl;
    std::cout << (map_1["one"] <= map_2["two"]) << std::endl;
    std::cout << (map_1["one"] <= map_3["three"]) << std::endl;
    std::cout << (map_2["two"] <= map_1["one"]) << std::endl;
    std::cout << (map_4["four"] <= map_1["one"]) << std::endl;
    std::cout << (map_1["one"] <= map_4["four"]) << std::endl;
    std::cout << ">" << std::endl;
    std::cout << (map_1["one"] > map_2["two"]) << std::endl;
    std::cout << (map_1["one"] > map_3["three"]) << std::endl;
    std::cout << (map_2["two"] > map_1["one"]) << std::endl;
    std::cout << (map_4["four"] > map_1["one"]) << std::endl;
    std::cout << (map_1["one"] > map_4["four"]) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (map_1["one"] >= map_2["two"])<< std::endl;
    std::cout << (map_1["one"] >= map_3["three"])<< std::endl;
    std::cout << (map_2["two"] >= map_1["one"])<< std::endl;
    std::cout << (map_4["four"] >= map_1["one"])<< std::endl;
    std::cout << (map_1["one"] >= map_4["four"])<< std::endl;
    //map_1["one"].resize(100000);
    std::cout << "<=" << std::endl;
    std::cout << (map_1["one"] <= map_2["two"]) << std::endl;
    std::cout << (map_1["one"] <= map_3["three"]) << std::endl;
    std::cout << (map_2["two"] <= map_1["one"]) << std::endl;
    std::cout << (map_4["four"] <= map_1["one"]) << std::endl;
    std::cout << (map_1["one"] <= map_4["four"]) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (map_1["one"] >= map_2["two"])<< std::endl;
    std::cout << (map_1["one"] >= map_3["three"])<< std::endl;
    std::cout << (map_2["two"] >= map_1["one"])<< std::endl;
    std::cout << (map_4["four"] >= map_1["one"])<< std::endl;
    std::cout << (map_1["one"] >= map_4["four"])<< std::endl;
}