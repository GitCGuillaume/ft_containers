#include "modifiers.hpp"

void    clear_custom()
{
    std::cout << "Clear custom, no values be displayed below." << std::endl;
    ft::vector<std::string>    vec(5, "test");

    vec.clear();
    for (ft::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    insert_custom()
{
    std::cout << "Insert custom tests" << std::endl;
    ft::vector<std::string>    vec;
    vec.insert(vec.begin(), "Insert first element");
    std::cout << "vec.begin() = " << vec[0] << std::endl;
    vec.insert(vec.begin() + 1, "Insert second element");
    std::cout << "vec.begin() + 1 = " << vec[1] << std::endl;
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    vec.insert(vec.end(), "Insert third element");
    std::cout << "vec.end() = " << vec[2] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
    vec.insert(vec.end(), "Insert fourth element");
    std::cout << "vec.end() = " << vec[3] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " "
        << vec[2] << " " << vec[3] << std::endl;
}

void    insert_100k_custom()
{
    ft::vector<double>  vec;

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

void    insert_reserve_100k_custom()
{
    ft::vector<double> vec;

    vec.reserve(100000);
    std::cout << "capacity vector capacity 100k : " << vec.capacity() << std::endl;
    for (double i = 0.000000; i < 200001.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), i);
    std::cout << "capacity vector capacity 100000 : " << vec.capacity() << std::endl;
}

void    insert_return_custom()
{
    std::cout << "Insert return custom" << std::endl;
    ft::vector<std::string>    vec;
    ft::vector<std::string>::iterator  it;
    it = vec.insert(vec.begin(), "one");
    std::cout << *it << std::endl;
}

void    count_insert_100_custom()
{
    std::cout << "count_insert_100_custom" << std::endl;
    ft::vector<double>  vec;

    vec.insert(vec.begin() + 0, 2, 0.000000);
    std::cout << "capacity vector begin() + 0 : " << vec.capacity() << std::endl;
    for  (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 1, 5, 1.000000);
    std::cout << "capacity vector begin() + 1 : " << vec.capacity() << std::endl;
    for  (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 2, 3, 2.000000);
    std::cout << "capacity vector begin() + 2 : " << vec.capacity() << std::endl;
    for  (ft::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (double i = 3.000000; i < 10000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity  20k : " << vec.capacity() << std::endl;
    for (double i = 10000.000000; i < 20000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity 50k : " << vec.capacity() << std::endl;
}