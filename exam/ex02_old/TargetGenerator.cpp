#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator()
{
	for (ft::vector<ATarget *>::iterator it = this->vec.begin(); it != this->vec.end(); it++)
	{
		delete *it;
	}
}

void	TargetGenerator::learnTargetType(ATarget* src)
{
	if (src)
		this->vec.push_back(src->clone());
}

void	TargetGenerator::forgetTargetType(std::string const &str)
{
	ft::vector<ATarget *>::iterator	it = this->vec.begin();

	while (it != this->vec.end())
	{
		if (*it && (*it)->getType().compare(str) == 0)
		{
			delete *it;
			this->vec.erase(it);
		}
		else
			it++;
	}
}

ATarget* TargetGenerator::createTarget(std::string const &str)
{
	ft::vector<ATarget *>::iterator	it = this->vec.begin();

	while (it != this->vec.end())
	{
		if (*it && (*it)->getType().compare(str) == 0)
		{
			return (*it);
		}
		it++;
	}
	return (NULL);
}
