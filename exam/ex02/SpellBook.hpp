#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"
#include <iostream>

class	SpellBook
{
	private:
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::vector<ASpell *>	vec;

	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell* src);
		void	forgetSpell(std::string const & str);
		ASpell*	createSpell(std::string const & str);
		void	res();
};

#endif
