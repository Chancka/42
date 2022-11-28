#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
	public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void	whoAmI();
	void	attack(std::string const &target);

	private:

	std::string	_name;
	
};

#endif
