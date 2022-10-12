#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string _type) : _type(_type)
{
	std::cout << "Default constructor called for Weapon" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destructor of Weapon called" << std::endl;
}

const std::string	&Weapon::getType()
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
