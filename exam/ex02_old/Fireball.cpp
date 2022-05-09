#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp"){}
Fireball::~Fireball(){}
Fireball::Fireball(Fireball const & src): ASpell(src.getName(), src.getEffects()){}
Fireball & Fireball::operator=(Fireball const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}
Fireball*	Fireball::clone() const
{
	Fireball*	fireball = new Fireball();
	return (fireball);
}
