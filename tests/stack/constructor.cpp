#include "constructor.hpp"

void    default_constructor_stack()
{
    std::cout << "Default constructor stack" << std::endl;
    TYPECONT::stack<int> stack;
    std::cout << "Default constructor stack with map container" << std::endl;
    TYPECONT::stack<int, std::map<int, int> >    stack_2;
}

void    constructor_stack_copy()
{
    std::cout << "Stack constructor copy" << std::endl;
    TYPECONT::stack<int> stack;

    for (int i = 0; i < 5; i++)
        stack.push(i);
    TYPECONT::stack<int> stack_cpy(stack);
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