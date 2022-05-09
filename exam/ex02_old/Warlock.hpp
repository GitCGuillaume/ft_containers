#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		Warlock();
		Warlock(Warlock const & src);
		Warlock & operator=(Warlock const & src);
		SpellBook	spellbook;

	public:
		Warlock(std::string const & name, std::string const & title);
		~Warlock();
		std::string const &	getName() const;
		std::string const &	getTitle() const;
		void	setTitle(std::string const & src);
		void	introduce() const;
		void	learnSpell(ASpell *src);
		void	forgetSpell(std::string str);
		void	launchSpell(std::string str, ATarget & src);
};

#endif
