#include "modifiers.hpp"

void    clear()
{
    std::cout << "Clear, no values to be displayed below." << std::endl;
    NAMESPACE::vector<std::string>    vec(5, "test");

    vec.clear();
    for (NAMESPACE::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    insert()
{
    std::cout << "Insert tests" << std::endl;
    NAMESPACE::vector<std::string>    vec;
    vec.insert(vec.begin(), "Insert first element");
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    std::cout << "vec.begin() = " << vec[0] << std::endl;
    vec.insert(vec.begin() + 1, "Insert second element");
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    std::cout << "vec.begin() + 1 = " << vec[1] << std::endl;
    vec.insert(vec.end(), "Insert third element");
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    std::cout << "vec.end() = " << vec[2] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
    vec.insert(vec.end(), "Insert fourth element");
    std::cout << "capacity vector = " << vec.capacity() << std::endl;
    std::cout << "vec.end() = " << vec[3] << std::endl;
    std::cout << vec[0] << " " << vec[1] << " "
        << vec[2] << " " << vec[3] << std::endl;
}

void    insert_100k()
{
    std::cout << "Insert 100k" << std::endl;
    NAMESPACE::vector<double>  vec;

    vec.insert(vec.begin() + 0, 0.000000);
    std::cout << "capacity vector begin() + 0 : " << vec.capacity() << std::endl;
    vec.insert(vec.begin() + 1, 1.000000);
    std::cout << "capacity vector begin() + 1 : " << vec.capacity() << std::endl;
    vec.insert(vec.begin() + 2, 2.000000);
    std::cout << "capacity vector begin() + 2 : " << vec.capacity() << std::endl;
    vec.resize(10);
    std::cout << "resize capacity vector = " << vec.capacity() << std::endl;
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
    std::cout << "Insert reserve 100k" << std::endl;
    NAMESPACE::vector<double> vec;

    vec.reserve(100000);
    std::cout << "capacity vector capacity 100k : " << vec.capacity() << std::endl;
    for (double i = 0.000000; i < 200001.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), i);
    std::cout << "capacity vector capacity 100000 : " << vec.capacity() << std::endl;
}

void    insert_return()
{
    std::cout << "Insert return" << std::endl;
    NAMESPACE::vector<std::string>    vec;
    NAMESPACE::vector<std::string>::iterator  it;
    it = vec.insert(vec.begin(), "one");
    std::cout << *it << std::endl;
}

void    count_insert_100()
{
    std::cout << "count_insert_100" << std::endl;
    NAMESPACE::vector<double>  vec;

    vec.insert(vec.begin() + 0, 2, 0.000000);
    std::cout << "capacity vector begin() + 0 : " << vec.capacity() << std::endl;
    for  (NAMESPACE::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 1, 5, 1.000000);
    std::cout << "capacity vector begin() + 1 : " << vec.capacity() << std::endl;
    for  (NAMESPACE::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 2, 3, 2.000000);
    std::cout << "capacity vector begin() + 2 : " << vec.capacity() << std::endl;
    for  (NAMESPACE::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    for (double i = 3.000000; i < 100.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity  20k : " << vec.capacity() << std::endl;
    for (double i = 100.000000; i < 200.000000; i++)
        vec.insert(vec.begin() + static_cast<size_t>(i), 2, i);
    std::cout << "capacity vector capacity 50k : " << vec.capacity() << std::endl;
    std::cout << "size : " << vec.size() << std::endl;
}

void    iterator_insert()
{
    std::cout << "iterator insert" << std::endl;
    NAMESPACE::vector<double> old_vec;
    NAMESPACE::vector<double> vec;
    double arr[5] = {0.000000,1.000000,2.000000,3.000000,4.000000};
    for (int i = 0; i < 5; i++)
        old_vec.insert(old_vec.end(), *(arr + i));
    vec.insert(vec.begin(), old_vec.begin(), old_vec.end());
    for  (NAMESPACE::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 3, old_vec.begin(), old_vec.end());
    for  (NAMESPACE::vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.insert(vec.begin() + 5, old_vec.begin(), old_vec.end());
    std::cout << "big pos first last insert" << std::endl;
    NAMESPACE::vector<int>    vec_2;
    for (unsigned int i = 0; i < 20000; i++)
        vec_2.insert(vec_2.end(), i);
    NAMESPACE::vector<int>    vec_3;
    vec_3.insert(vec_3.begin(), vec_2.begin(), vec_2.end());
}

void	iterator_input_insert_range()
{
	std::cout << "Input Tag Iterator Insert" << std::endl;
	NAMESPACE::vector<char>	vec;
    NAMESPACE::vector<char>	vec_2;
    NAMESPACE::vector<char>	vec_3;
    NAMESPACE::vector<char>	vec_4;
    NAMESPACE::vector<char>	vec_5;
	std::stringstream str("1 2 3");
    std::stringstream str2("1 2 34");
    std::stringstream str3("1 2 3 4");
    std::stringstream str4("");
    std::stringstream str5("1");

    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str4), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
	std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    str.str("1 2 3");
    str2.str("1 2 34");
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.end(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    str.str("1 2 3");
    vec_2.insert(vec_2.end(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.end(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str4), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin() + 2, std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.begin() + 3, std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str4), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    str.str("1 2 3");
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.end(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    str2.str("1 2 34");
    vec_2.insert(vec_2.end(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_3.insert(vec_3.end(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str), std::istreambuf_iterator<char>());
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    str3.str("1 2 3 4");
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str5), std::istreambuf_iterator<char>());
    std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
    str.str("1 2 3");
    str2.str("1 2 34");
    str3.str("1 2 3 4");
    str4.str("");
    str5.str("1");
    vec.insert(vec.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    str3.str("1 2 3 4");
    vec_2.insert(vec_2.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    str2.str("1 2 34");
    vec_3.insert(vec_3.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    str3.str("1 2 3 4");
    vec_4.insert(vec_4.begin(), std::istreambuf_iterator<char>(str3), std::istreambuf_iterator<char>());
    vec_5.insert(vec_5.begin(), std::istreambuf_iterator<char>(str2), std::istreambuf_iterator<char>());
    for (NAMESPACE::vector<char>::iterator it_start = vec.begin(); it_start != vec.end(); ++it_start)
		std::cout << *it_start << std::endl;
    for (NAMESPACE::vector<char>::iterator it_start = vec_2.begin(); it_start != vec_2.end(); ++it_start)
		std::cout << *it_start << std::endl;
    for (NAMESPACE::vector<char>::iterator it_start = vec_3.begin(); it_start != vec_3.end(); ++it_start)
		std::cout << *it_start << std::endl;
	std::cout << "Insert range constructor : " << vec.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_2.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_2.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_3.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_3.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_4.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_4.size() << std::endl;
    std::cout << "Insert range constructor : " << vec_5.capacity() << std::endl;
    std::cout << "Insert size constructor : " << vec_5.size() << std::endl;
}

void    push_back_vector()
{
    std::cout << "push back vector" << std::endl;
    NAMESPACE::vector<double> vec;

    for (double i = 0; i < 50000; i++)
        vec.push_back(i);
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    pop_back_vector()
{
    std::cout << "pop back vector" << std::endl;

    NAMESPACE::vector<int>    vec;

    vec.push_back(1);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    vec.push_back(2);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    vec.push_back(3);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    vec.pop_back();
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.pop_back();
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    vec.pop_back();
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
}

void    resize()
{
    std::cout << "Resize vector" << std::endl;
    NAMESPACE::vector<int>    vec;

    vec.resize(5);
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "e1 : " << *it << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for (int i = 1; i < 6; i++)
        vec.push_back(i);
    vec.resize(15, 42);
    std::cout << "capacity : " << vec.capacity() << std::endl;
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "e2 : " << *it << std::endl;
     std::cout << "size : " << vec.size() << std::endl;
    for (int i = 4; 0 < i; i --)
    {
        vec.resize(i);
        std::cout << "size : " << vec.size() << std::endl;
        std::cout << "capacity : " << vec.capacity() << std::endl;
        for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "elem : " << *it << std::endl;
    }
    vec.resize(5);
    vec.resize(1);
    vec.resize(5);
    vec.resize(0);
    vec.resize(0);
    vec.resize(0);
    vec.resize(5);
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << std::endl;
    vec.resize(0);
    std::cout << "resize(0)" << std::endl;
    for  (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}

void    swap_vector()
{
    std::cout << "SWAP" << std::endl;
    NAMESPACE::vector<int>    vec_1;
    NAMESPACE::vector<int>    vec_2;

    vec_1.swap(vec_2);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(7);
    vec_1.reserve(5);
    vec_2.push_back(5);
    vec_2.push_back(6);
    NAMESPACE::vector<int>::iterator it1 = vec_1.begin();
    NAMESPACE::vector<int>::iterator it2 = vec_2.begin();
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
    for  (NAMESPACE::vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
        std::cout << *it << std::endl;    
    std::cout << "vec_2" << std::endl;
    for  (NAMESPACE::vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it1 validity : " << (it1 == vec_1.begin()) << std::endl;
    std::cout << "it2 validity : " << (it2 == vec_2.begin()) << std::endl;
    std::cout << "it1 validity : " << (it1 == vec_2.begin()) << std::endl;
    std::cout << "it2 validity : " << (it2 == vec_1.begin()) << std::endl;
    while (it1 != vec_2.end())
    {
        std::cout << "*it1 : " << *it1 << std::endl;
        ++it1;
    }
    while (it2 != vec_1.end())
    {
        std::cout << "*it2 : " << *it2 << std::endl;
        ++it2;
    }
}

void    swap_vector_non_member()
{
    std::cout << "Non-Member SWAP" << std::endl;
    NAMESPACE::vector<int>    vec_1;
    NAMESPACE::vector<int>    vec_2;

    NAMESPACE::swap(vec_1, vec_2);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(7);
    vec_1.reserve(5);
    vec_2.push_back(5);
    vec_2.push_back(6);
    NAMESPACE::vector<int>::iterator it1 = vec_1.begin();
    NAMESPACE::vector<int>::iterator it2 = vec_2.begin();
    std::cout << "BEFORE" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    NAMESPACE::swap(vec_1, vec_2);
    std::cout << "AFTER" << std::endl;
    std::cout << "vec_1 size : " << vec_1.size() << std::endl
        << "vec_1 capacity : " << vec_1.capacity() << std::endl;
    std::cout << "vec_2 size : " << vec_2.size() << std::endl
        << "vec_2 capacity : " << vec_2.capacity() << std::endl;
    std::cout << "vec_1" << std::endl;
    for  (NAMESPACE::vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
        std::cout << *it << std::endl;    
    std::cout << "vec_2" << std::endl;
    for  (NAMESPACE::vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "it1 validity : " << (it1 == vec_1.begin()) << std::endl;
    std::cout << "it2 validity : " << (it2 == vec_2.begin()) << std::endl;
    std::cout << "it1 validity : " << (it1 == vec_2.begin()) << std::endl;
    std::cout << "it2 validity : " << (it2 == vec_1.begin()) << std::endl;
    while (it1 != vec_2.end())
    {
        std::cout << "*it1 : " << *it1 << std::endl;
        ++it1;
    }
    while (it2 != vec_1.end())
    {
        std::cout << "*it2 : " << *it2 << std::endl;
        ++it2;
    }
}
