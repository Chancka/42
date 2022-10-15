#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

class FragTrap : public virtual ScavTrap
{
	public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	void	highFivesGuys(void);

	private:

	
};

#endif
