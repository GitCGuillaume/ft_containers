#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include "../../includes/containers/vector.hpp"
#include "ASpell.hpp"
#include <iostream>

class	SpellBook
{
	private:
		ft::vector<ASpell *>	vec;
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);

	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell* src);
		void	forgetSpell(std::string const & str);
		void	forgetSpell2(std::string const & str);
		ASpell*	createSpell(std::string const & str);
};

#endif
