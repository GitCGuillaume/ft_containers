#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(std::string const type) : _type(type){}
ATarget::~ATarget(){}
ATarget::ATarget(ATarget const & src)
{
	this->_type = src.getType();
}
ATarget & ATarget::operator=(ATarget const & src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}
std::string	ATarget::getType() const
{
	return (this->_type);
}
void	ATarget::getHitBySpell(ASpell const & src) const
{
	std::cout << this->_type << " has been " << src.getEffects() << std::endl;
}
