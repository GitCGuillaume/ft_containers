#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	private:
		std::string	_type;

	public:
		ATarget();
		ATarget(std::string const type);
		virtual ~ATarget();
		ATarget(ATarget const & src);
		ATarget & operator=(ATarget const & src);
		std::string	getType() const;
		virtual ATarget*	clone() const = 0;
		void	getHitBySpell(ASpell const & src) const;
};

#endif
