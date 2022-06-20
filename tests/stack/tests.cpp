#include "tests.hpp"

void    stack_empty()
{
    std::cout << "Stack empty" << std::endl;
    TYPECONT::stack<int> stack;

    std::cout << stack.empty() << std::endl;
    stack.push(1);
    std::cout << stack.empty() << std::endl;
}

void    stack_size()
{
    std::cout << "Stack size" << std::endl;
    TYPECONT::stack<int> stack;

    std::cout << stack.size() << std::endl;
    stack.push(1);
    std::cout << stack.size() << std::endl;
}

void    stack_equal()
{
    std::cout << "Operator stack" << std::endl;
    TYPECONT::stack<int>    stack_1;
    TYPECONT::stack<int>    stack_2;
    TYPECONT::stack<int>    stack_3;
    TYPECONT::stack<int>    stack_4;

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