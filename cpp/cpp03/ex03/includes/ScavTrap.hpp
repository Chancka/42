#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	void	guardGate();
	
	private:

	
};

#endif
