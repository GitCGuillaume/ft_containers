#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh(Fwoosh const & src);
		Fwoosh & operator=(Fwoosh const & src);
		Fwoosh*	clone() const;
};

#endif
