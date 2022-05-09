#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class	Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		std::string	getType() const;
		Dummy*	clone() const;
};

#endif
