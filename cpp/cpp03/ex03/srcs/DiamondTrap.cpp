#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default")
{
	this->_health = FragTrap::_health;
	ClapTrap::_name = _name + "_clap_name";
	this->_energy = ScavTrap::_energy;
	this->_ad = FragTrap::_ad;
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	this->_health = FragTrap::_health;
	ClapTrap::_name = _name + "_clap_name";
	this->_energy = ScavTrap::_energy;
	this->_ad = FragTrap::_ad;
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "Copy constructor called for DiamondTrap" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Assignation constructor called for DiamondTrap" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

void	DiamondTrap::attack(std::string	const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name of DiamondTrap : " << this->_name << std::endl;
	std::cout << "Name of ClapTrap : " << ClapTrap::_name << std::endl;
}
