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
    vec.insert(vec.end(), "Insert fourth element");
    std::cout << "vec.end() = " << vec[3] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " "
        << vec[2] << " " << vec[3] << std::endl;
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

void    insert_return()
{
        std::cout << "Insert return" << std::endl;
    std::vector<std::string>    vec;
    std::vector<std::string>::iterator  it;
    it = vec.insert(vec.begin(), "one");
    std::cout << *it << std::endl;
}

void    count_insert_100()
{
    std::cout << "count_insert_100" << std::endl;
    std::vector<double>  vec;

    vec.insert(vec.begin() + 0, 2, 0.000000);
    std::cout << "capacity vector begin() + 0 : " << vec.capacity() << std::endl;
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 1, 5, 1.000000);
    std::cout << "capacity vector begin() + 1 : " << vec.capacity() << std::endl;
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 2, 3, 2.000000);
    std::cout << "capacity vector begin() + 2 : " << vec.capacity() << std::endl;
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (double i = 3.000000; i < 10000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity  20k : " << vec.capacity() << std::endl;
    for (double i = 10000.000000; i < 20000.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity 50k : " << vec.capacity() << std::endl;
}

void    iterator_insert()
{
    std::cout << "iterator insert" << std::endl;
    std::vector<double> old_vec;
    std::vector<double> vec;
    double arr[5] = {0.000000,1.000000,2.000000,3.000000,4.000000};
    for (int i = 0; i < 5; i++)
        old_vec.insert(old_vec.end(), *(arr + i));
    vec.insert(vec.begin(), old_vec.begin(), old_vec.end());
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 3, old_vec.begin(), old_vec.end());
    for  (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 5, old_vec.begin(), old_vec.end());
}

void    push_back_vector()
{
    std::cout << "push back vector" << std::endl;
    std::vector<double> vec;

    for (double i = 0; i < 50000; i++)
        vec.push_back(i);
    //for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
      // std::cout << *it << std::endl;
}

void    pop_back_vector()
{
    std::cout << "pop back vector" << std::endl;

    std::vector<int>    vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.pop_back();
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.pop_back();
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.pop_back();
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    resize()
{
    std::cout << "Resize vector" << std::endl;
    std::vector<int>    vec;

    vec.resize(5);
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "e1 : " << *it << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    vec.resize(15, 42);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "e2 : " << *it << std::endl;
     std::cout << "size : " << vec.size() << std::endl;
    for (int i = 4; 0 < i; i --)
    {
        vec.resize(i);
        std::cout << "size : " << vec.size() << std::endl;
        std::cout << "capacity : " << vec.capacity() << std::endl;
        for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "elem : " << *it << std::endl;
    }
    vec.resize(5);
    vec.resize(1);
    vec.resize(5);
    vec.resize(0);
    vec.resize(0);
    vec.resize(0);
    vec.resize(5);
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << std::endl;
    vec.resize(0);
    std::cout << "resize(0)" << std::endl;
    for  (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    swap_vector()
{
    std::cout << "SWAP" << std::endl;
    std::vector<int>    vec_1;
    std::vector<int>    vec_2;

    //for (int i = 0; i < 100000; i++)
    //    vec_1.push_back(i);
    //for (int i = 110000; 130000; i++)
    //    vec_2.push_back(i);
    vec_1.swap(vec_2);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(7);
    vec_1.reserve(5);
    vec_2.push_back(5);
    vec_2.push_back(6);
    std::vector<int>::iterator it1 = vec_1.begin();
    std::vector<int>::iterator it2 = vec_2.begin();
    std::cout << "BEFORE" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    vec_1.swap(vec_2);
    std::cout << "AFTER" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    std::cout << "vec_1" << std::endl;
    for  (std::vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
        std::cout << *it << std::endl;    
    std::cout << "vec_2" << std::endl;
    for  (std::vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it_1 validity : " << (it1 == vec_1.begin()) << std::endl;
    std::cout << "it_2 validity : " << (it2 == vec_2.begin()) << std::endl;

}

void    swap_vector_non_member()
{
    std::cout << "Non-Member SWAP" << std::endl;
    std::vector<int>    vec_1;
    std::vector<int>    vec_2;

    //for (int i = 0; i < 100000; i++)
    //    vec_1.push_back(i);
    //for (int i = 110000; 130000; i++)
    //    vec_2.push_back(i);
    std::swap(vec_1, vec_2);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(7);
    vec_1.reserve(5);
    vec_2.push_back(5);
    vec_2.push_back(6);
    std::vector<int>::iterator it1 = vec_1.begin();
    std::vector<int>::iterator it2 = vec_2.begin();
    std::cout << "BEFORE" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    std::swap(vec_1, vec_2);
    std::cout << "AFTER" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    std::cout << "vec_1" << std::endl;
    for  (std::vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
        std::cout << *it << std::endl;    
    std::cout << "vec_2" << std::endl;
    for  (std::vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it_1 validity : " << (it1 == vec_1.begin()) << std::endl;
    std::cout << "it_2 validity : " << (it2 == vec_2.begin()) << std::endl;
}