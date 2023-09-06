#include "stack_standard_stl.hpp"

void    stl_vector(void)
{
    std::cout << "stl VECTOR test" << std::endl;
    NAMESPACE::stack<int, std::vector<int> > stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
}

void    stl_deque(void)
{
    std::cout << "stl DEQUE test" << std::endl;
    NAMESPACE::stack<int, std::deque<int> > stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
}

void    stl_list(void)
{
    std::cout << "stl LIST test" << std::endl;
    NAMESPACE::stack<int, std::list<int> > stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
    std::cout << (stack.top()) << std::endl;;
    stack.pop();
}