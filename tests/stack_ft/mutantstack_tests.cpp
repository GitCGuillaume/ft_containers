#include "constructor.hpp"

static void	type_cpy(MutantStack<int>& mstack)
{
	MutantStack<int>	s(mstack);
	MutantStack<int>::iterator it = s.begin();
	MutantStack<int>::iterator ite = s.end();

	std::cout << std::endl << "Display s(copy) MutantStack" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	type_vector()
{
	ft::vector<int>	vec;
	ft::vector<int>::const_iterator it;
	ft::vector<int>::const_iterator ite;

	vec.push_back(5);
	vec.push_back(17);
	vec.pop_back();
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	vec.push_back(0);
	vec.push_back(10);
	vec.push_back(20000);
	vec.push_back(30000);
	it = vec.begin();
	ite = vec.end();
	std::cout << std::endl << "Vector display" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	type_reverse_iterate(MutantStack<int>&	mstack)
{
	std::cout << std::endl << "Reverse Iterate mstack" << std::endl;
	MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator rite = mstack.rend();

	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

static void	type_iterate(MutantStack<int>&	mstack)
{
	std::cout << "Iterate mstack" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	stack_mutant_stack()
{
	std::cout << "Mutant Stack" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl
		<< "POP" << std::endl;
	mstack.pop();
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	for (int i = 0; i < 5; i++)
		mstack.push(i);
	mstack.push(0);
	mstack.push(10);
	mstack.push(20000);
	mstack.push(30000);
	type_iterate(mstack);
	type_reverse_iterate(mstack);
	type_cpy(mstack);
	type_vector();
}