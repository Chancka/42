#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ScavTrap()
{
	std::cout << "Default constructor called for FragTrap" << std::endl;
	this->_energy = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
	std::cout << "Constructor with string called for FragTrap" << std::endl;
	this->_energy = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) , ScavTrap(other)
{
	std::cout << "Copy constructor called for FragTrap" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignation constructor called for FragTrap" << std::endl;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_ad = other._ad;
	this->_name = other._name;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " ask for a high five !" << std::endl;
}
