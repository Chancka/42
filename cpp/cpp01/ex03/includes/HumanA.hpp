#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "../includes/Weapon.hpp"

class HumanA
{
	public:

	HumanA(std::string _name, Weapon &_weapon);
	~HumanA();
	void	attack(void);

	private:

	std::string	_name;
	Weapon		&_weapon;


};

#endif
