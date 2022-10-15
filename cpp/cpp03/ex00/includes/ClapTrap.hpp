#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:

	ClapTrap();
	ClapTrap(std::string	_name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	private:

	std::string		_name;
	unsigned int	_health;
	unsigned int	_energy;
	unsigned int	_ad;
	
};

#endif
