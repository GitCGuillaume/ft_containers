#include "operator.hpp"

void    equal_vector()
{
    std::cout << "Operator" << std::endl;
    TYPECONT::vector<int>    vec_1;
    TYPECONT::vector<int>    vec_2;
    TYPECONT::vector<int>    vec_3;
    TYPECONT::vector<int>    vec_4;

    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_2.push_back(4);
    vec_2.push_back(5);
    vec_3.push_back(1);
    vec_3.push_back(2);
    vec_3.push_back(3);
    vec_4.push_back(4);
    vec_4.push_back(5);
    vec_4.push_back(3);
    std::cout << "==" << std::endl;
    std::cout << (vec_1 == vec_2) << std::endl;
    std::cout << (vec_2 == vec_1) << std::endl;
    std::cout << (vec_1 == vec_3) << std::endl;
    std::cout << (vec_1 == vec_4) << std::endl;
    std::cout << "!=" << std::endl;
    std::cout << (vec_1 != vec_2) << std::endl;
    std::cout << (vec_2 != vec_1) << std::endl;
    std::cout << (vec_1 != vec_3) << std::endl;
    std::cout << (vec_1 != vec_4) << std::endl;
    std::cout << "<" << std::endl;
    std::cout << (vec_1 < vec_2) << std::endl;
    std::cout << (vec_1 < vec_3) << std::endl;
    std::cout << (vec_2 < vec_1) << std::endl;
    std::cout << (vec_1 < vec_4) << std::endl;
    std::cout << (vec_4 < vec_1) << std::endl;
    std::cout << "<=" << std::endl;
    std::cout << (vec_1 <= vec_2) << std::endl;
    std::cout << (vec_1 <= vec_3) << std::endl;
    std::cout << (vec_2 <= vec_1) << std::endl;
    std::cout << (vec_4 <= vec_1) << std::endl;
    std::cout << (vec_1 <= vec_4) << std::endl;
    std::cout << ">" << std::endl;
    std::cout << (vec_1 > vec_2) << std::endl;
    std::cout << (vec_1 > vec_3) << std::endl;
    std::cout << (vec_2 > vec_1) << std::endl;
    std::cout << (vec_4 > vec_1) << std::endl;
    std::cout << (vec_1 > vec_4) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (vec_1 >= vec_2)<< std::endl;
    std::cout << (vec_1 >= vec_3)<< std::endl;
    std::cout << (vec_2 >= vec_1)<< std::endl;
    std::cout << (vec_4 >= vec_1)<< std::endl;
    std::cout << (vec_1 >= vec_4)<< std::endl;
    vec_1.resize(100000);
     std::cout << "<=" << std::endl;
    std::cout << (vec_1 <= vec_2) << std::endl;
    std::cout << (vec_1 <= vec_3) << std::endl;
    std::cout << (vec_2 <= vec_1) << std::endl;
    std::cout << (vec_4 <= vec_1) << std::endl;
    std::cout << (vec_1 <= vec_4) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (vec_1 >= vec_2)<< std::endl;
    std::cout << (vec_1 >= vec_3)<< std::endl;
    std::cout << (vec_2 >= vec_1)<< std::endl;
    std::cout << (vec_4 >= vec_1)<< std::endl;
    std::cout << (vec_1 >= vec_4)<< std::endl;
}