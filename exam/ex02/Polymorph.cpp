#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter"){}
Polymorph::~Polymorph(){}
Polymorph::Polymorph(Polymorph const & src) : ASpell(src.getName(), src.getEffects()){}
Polymorph & Polymorph::operator=(Polymorph const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}
Polymorph*	Polymorph::clone() const
{
	Polymorph*	polymorph = new Polymorph();
	return (polymorph);
}
