#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const &	Warlock::getName() const
{
	return (this->_name);
}

std::string const &	Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const & src)
{
	this->_title = src;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << std::endl;
}

void	Warlock::learnSpell(ASpell *src)
{
	if (src)
		this->spellbook.learnSpell(src);
}
void	Warlock::forgetSpell(std::string str)
{
	this->spellbook.forgetSpell(str);
}

void	Warlock::launchSpell(std::string str, ATarget & src)
{
	ATarget const *is_null = NULL;

	if (is_null == &src)
		return ;
	ASpell*	spell = this->spellbook.createSpell(str);
	if (spell)
		spell->launch(src);
}
