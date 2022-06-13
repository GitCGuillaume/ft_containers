#include "tests.hpp"

void    stack_empty_custom()
{
    std::cout << "Stack empty CUSTOM" << std::endl;
    ft::stack<int> stack;

    std::cout << stack.empty() << std::endl;
    stack.push(1);
    std::cout << stack.empty() << std::endl;
}

void    stack_size_custom()
{
    std::cout << "Stack size CUSTOM" << std::endl;
    ft::stack<int> stack;

    std::cout << stack.size() << std::endl;
    stack.push(1);
    std::cout << stack.size() << std::endl;
}

void    stack_equal_custom()
{
    std::cout << "Operator stack CUSTOM" << std::endl;
    ft::stack<int>    stack_1;
    ft::stack<int>    stack_2;
    ft::stack<int>    stack_3;
    ft::stack<int>    stack_4;

    stack_1.push(1);
    stack_1.push(2);
    stack_1.push(3);
    stack_2.push(4);
    stack_2.push(5);
    stack_3.push(1);
    stack_3.push(2);
    stack_3.push(3);
    stack_4.push(4);
    stack_4.push(5);
    stack_4.push(3);
    std::cout << "==" << std::endl;
    std::cout << (stack_1 == stack_2) << std::endl;
    std::cout << (stack_2 == stack_1) << std::endl;
    std::cout << (stack_1 == stack_3) << std::endl;
    std::cout << (stack_1 == stack_4) << std::endl;
    std::cout << "!=" << std::endl;
    std::cout << (stack_1 != stack_2) << std::endl;
    std::cout << (stack_2 != stack_1) << std::endl;
    std::cout << (stack_1 != stack_3) << std::endl;
    std::cout << (stack_1 != stack_4) << std::endl;
    std::cout << "<" << std::endl;
    std::cout << (stack_1 < stack_2) << std::endl;
    std::cout << (stack_1 < stack_3) << std::endl;
    std::cout << (stack_2 < stack_1) << std::endl;
    std::cout << (stack_1 < stack_4) << std::endl;
    std::cout << (stack_4 < stack_1) << std::endl;
    std::cout << "<=" << std::endl;
    std::cout << (stack_1 <= stack_2) << std::endl;
    std::cout << (stack_1 <= stack_3) << std::endl;
    std::cout << (stack_2 <= stack_1) << std::endl;
    std::cout << (stack_4 <= stack_1) << std::endl;
    std::cout << (stack_1 <= stack_4) << std::endl;
    std::cout << ">" << std::endl;
    std::cout << (stack_1 > stack_2) << std::endl;
    std::cout << (stack_1 > stack_3) << std::endl;
    std::cout << (stack_2 > stack_1) << std::endl;
    std::cout << (stack_4 > stack_1) << std::endl;
    std::cout << (stack_1 > stack_4) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (stack_1 >= stack_2)<< std::endl;
    std::cout << (stack_1 >= stack_3)<< std::endl;
    std::cout << (stack_2 >= stack_1)<< std::endl;
    std::cout << (stack_4 >= stack_1)<< std::endl;
    std::cout << (stack_1 >= stack_4)<< std::endl;
     std::cout << "<=" << std::endl;
    std::cout << (stack_1 <= stack_2) << std::endl;
    std::cout << (stack_1 <= stack_3) << std::endl;
    std::cout << (stack_2 <= stack_1) << std::endl;
    std::cout << (stack_4 <= stack_1) << std::endl;
    std::cout << (stack_1 <= stack_4) << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (stack_1 >= stack_2)<< std::endl;
    std::cout << (stack_1 >= stack_3)<< std::endl;
    std::cout << (stack_2 >= stack_1)<< std::endl;
    std::cout << (stack_4 >= stack_1)<< std::endl;
    std::cout << (stack_1 >= stack_4)<< std::endl;
}