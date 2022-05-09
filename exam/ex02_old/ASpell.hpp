#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell(std::string const name, std::string const effects);
		virtual ~ASpell();
		ASpell(ASpell const & src);
		ASpell & operator=(ASpell const & src);
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell*	clone() const = 0;
		void	launch(ATarget const & src) const;
};

#endif
