#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
	this->FragTrap::_health = 100;
	this->ScavTrap::_energy = 50;
	this->FragTrap::_ad = 30;
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	this->FragTrap::_health = 100;
	this->ScavTrap::_energy = 50;
	this->FragTrap::_ad = 30;
	std::cout << "Constructor with string called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) , FragTrap(other) , ScavTrap(other)
{
	std::cout << "Copy constructor called for DiamondTrap" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "Assignation constructor called for DiamondTrap" << std::endl;
	ClapTrap::operator=(other);
	ScavTrap();
	FragTrap();
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name of DiamondTrap : " << this->_name << std::endl;
	std::cout << "Name of ClapTrap : " << ClapTrap::_name << std::endl;
}
