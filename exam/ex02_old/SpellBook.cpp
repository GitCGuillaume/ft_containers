#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook()
{
	for (ft::vector<ASpell *>::iterator it = this->vec.begin(); it != this->vec.end(); it++)
		delete *it;
}

void	SpellBook::learnSpell(ASpell* src)
{
	if (src)
		this->vec.push_back(src->clone());
}
void	SpellBook::forgetSpell(std::string const & str)
{
	ft::vector<ASpell *>::iterator	it = this->vec.begin();

	while (it != this->vec.end())
	{
		if (*it && (*it)->getName().compare(str) == 0)
		{
		//	delete *it;
			this->vec.erase(it);
		}
		else
			it++;
	}
}

ASpell*	SpellBook::createSpell(std::string const & str)
{
	ft::vector<ASpell *>::iterator	it = this->vec.begin();

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
