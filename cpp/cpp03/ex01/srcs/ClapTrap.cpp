#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _ad(0)
{
	std::cout << "Constructor with string called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap() : _name("Default"), _health(10), _energy(10), _ad(0)
{
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called for ClapTrap" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignation constructor called for ClapTrap" << std::endl;
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_ad = other._ad;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->_energy)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << this->_name << " attacks " << target << ", causing " << this->_ad << " point of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << this->_name << " is already dead" << std::endl;
		return ;
	}
	if (amount > this->_health)
		this->_health = 0;
	else
		this->_health = this->_health - amount;
	if (this->_health == 0)
	{
		std::cout << this->_name << " take " << amount << " damage and die !" << std::endl;
		return ;
	}
	std::cout << this->_name << " take " << amount << " damage !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy)
	{
		std::cout << this->_name << " has no energy" << std::endl;
		return ;
	}
	if (this->_health == 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_health = this->_health + amount;
	std::cout << this->_name << " is healed " << amount << " health and now has " << this->_health << " health !" << std::endl;
}
