#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook()
{
	for (std::vector<ASpell *>::iterator it = this->vec.begin(); it != this->vec.end(); it++)
		delete *it;
}

void	SpellBook::learnSpell(ASpell* src)
{
	if (src)
		this->vec.push_back(src->clone());
}
void	SpellBook::forgetSpell(std::string const & str)
{
	std::vector<ASpell *>::iterator	it = this->vec.begin();

	while (it != this->vec.end())
	{
		if (*it && (*it)->getName().compare(str) == 0)
		{
			delete *it;
			this->vec.erase(it);
		}
		else
			it++;
	}
}

ASpell*	SpellBook::createSpell(std::string const & str)
{
	std::vector<ASpell *>::iterator	it = this->vec.begin();

	while (it != this->vec.end())
	{
		if (*it && (*it)->getName().compare(str) == 0)
		{
			return (*it);
		}
		it++;
	}
	return (NULL);
}

void	SpellBook::res()
{
	this->vec.resize(10);
	std::vector<ASpell *>::iterator	it = this->vec.begin();
	while (it != this->vec.end())
	{
		std::cout << "e : " << *it << std::endl;
		it++;
	}
}
