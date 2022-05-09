#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell(std::string("Fwoosh"), std::string("fwooshed")){}
Fwoosh::~Fwoosh(){}
Fwoosh::Fwoosh(Fwoosh const & src) : ASpell(src.getName(), src.getEffects()){}
Fwoosh & Fwoosh::operator=(Fwoosh const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}

Fwoosh*	Fwoosh::clone() const
{
	Fwoosh*	fwoosh = new Fwoosh();
	return (fwoosh);
}
