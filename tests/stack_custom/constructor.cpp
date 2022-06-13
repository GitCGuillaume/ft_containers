#include "constructor.hpp"

void    default_constructor_stack_custom()
{
    std::cout << "Default constructor stack CUSTOM" << std::endl;
    ft::stack<int> stack;
    std::cout << "Default constructor stack with map container CUSTOM" << std::endl;
    ft::stack<int, ft::map<int, int> >    stack_2;
}

void    constructor_stack_copy_custom()
{
    std::cout << "Stack constructor copy CUSTOM" << std::endl;
    ft::stack<int> stack;

    for (int i = 0; i < 5; i++)
        stack.push(i);
    ft::stack<int> stack_cpy(stack);
    for (int i = 0; i < 5; i++)
    {
        std::cout << "stack_cpy.pop() : " << stack_cpy.top() << std::endl;
        stack_cpy.pop();
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << "stack.pop() : " << stack.top() << std::endl;
        stack.pop();
    }
}