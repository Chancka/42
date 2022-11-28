#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor with string called for ScavTrap" << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called for ScavTrap" << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignation constructor called for ScavTrap" << std::endl;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_ad = other._ad;
	this->_name = other._name;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " mode gate keeper activated" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (!this->_energy)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
}
