#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include "../../includes/containers/vector.hpp"
#include <iostream>

class	TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator(TargetGenerator const & src));
		TargetGenerator & operator=(TargetGenerator const & src);
		ft::vector<ATarget *>	vec;

	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget* src);
		void	forgetTargetType(std::string const & str);
		ATarget*	createTarget(std::string const & str);
};

#endif
