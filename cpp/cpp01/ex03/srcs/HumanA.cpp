#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : _name(_name), _weapon(_weapon)
{
	std::cout << "Default constructor called for HumanA" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor of HumanA called" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
