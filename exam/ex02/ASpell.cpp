#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(std::string const name, std::string const effects) : _name(name), _effects(effects){}
ASpell::~ASpell(){}
ASpell::ASpell(ASpell const & src)
{
	this->_name = src.getName();
	this->_effects = src.getEffects();
}
ASpell & ASpell::operator=(ASpell const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}
std::string ASpell::getName() const
{
	return (this->_name);
}
std::string ASpell::getEffects() const
{
	return (this->_effects);
}
void	ASpell::launch(ATarget const & src) const
{
	src.getHitBySpell(*this);
}
