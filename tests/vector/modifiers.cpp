#include "modifiers.hpp"

void    clear()
{
    std::cout << "Clear, no values be displayed below." << std::endl;
    std::vector<std::string>    vec(5, "test");

    vec.clear();
    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    insert()
{
    std::cout << "Insert tests" << std::endl;
    std::vector<std::string>    vec;
    vec.insert(vec.begin(), "Insert first element");
    std::cout << "vec.begin() = " << vec[0] << std::endl;
    vec.insert(vec.begin() + 1, "Insert second element");
    std::cout << "vec.begin() + 1 = " << vec[1] << std::endl;
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    vec.insert(vec.end(), "Insert third element");
    std::cout << "vec.end() = " << vec[2] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
}

void    insert_100k()
{
    std::vector<double>  vec;

    vec.insert(vec.begin() + 0, 0.000000);
    std::cout << "capacity vector begin() + 0 : " << vec.capacity() << std::endl;
    vec.insert(vec.begin() + 1, 1.000000);
    std::cout << "capacity vector begin() + 1 : " << vec.capacity() << std::endl;
    vec.insert(vec.begin() + 2, 2.000000);
    std::cout << "capacity vector begin() + 2 : " << vec.capacity() << std::endl;
    for (double i = 3.000000; i < 50000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), i);
    std::cout << vec[0] << " " << vec[49999] << std::endl;
    std::cout << "capacity vector capacity  50k : " << vec.capacity() << std::endl;
    for (double i = 50000.000000; i < 100000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), i);
    std::cout << "capacity vector capacity 100k : " << vec.capacity() << std::endl;
}

void    insert_reserve_100k()
{
    std::vector<double> vec;

    vec.reserve(100000);
    std::cout << "capacity vector capacity 100k : " << vec.capacity() << std::endl;
    for (double i = 0.000000; i < 200001.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), i);
    std::cout << "capacity vector capacity 100000 : " << vec.capacity() << std::endl;
}