#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string _name) : _name(_name)
{
	std::cout << "Default constructor called for HumanB" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destructor of HumanB called" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
