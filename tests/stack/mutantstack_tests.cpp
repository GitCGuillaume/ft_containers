#include "constructor.hpp"

static void	std_cpy(MutantStack<int>& mstack)
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

static void	std_vector()
{
	std::vector<int>	vec;
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite;

	vec.push_back(5);
	vec.push_back(17);
	vec.pop_back();
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	for (int i = 0; i < 10; i++)
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

static void	std_map()
{
	std::map<int, int>	vec;
	std::map<int, int>::const_iterator it;
	std::map<int, int>::const_iterator ite;

	vec.insert(std::make_pair(5, 5));
	vec.insert(std::make_pair(17, 17));
	vec.erase(17);
	vec.insert(std::make_pair(3, 3));
	vec.insert(std::make_pair(5, 5));
	vec.insert(std::make_pair(737, 737));
	for (int i = 0; i < 10; i++)
		vec.insert(std::make_pair(i, i));
	vec.insert(std::make_pair(0, 0));
	vec.insert(std::make_pair(10, 10));
	vec.insert(std::make_pair(20000, 20000));
	vec.insert(std::make_pair(30000, 30000));
	it = vec.begin();
	ite = vec.end();
	std::cout << std::endl << "Map display" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << it->first << it->second << std::endl;
		++it;
	}
}

static void	std_reverse_iterate(MutantStack<int>&	mstack)
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

static void	std_iterate(MutantStack<int>&	mstack)
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

void	std_mustant_stack()
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
	std_iterate(mstack);
	std_reverse_iterate(mstack);
	std_cpy(mstack);
	std_vector();
	std_map();
}
