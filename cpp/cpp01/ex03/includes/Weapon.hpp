#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:

	Weapon(std::string _type);
	~Weapon();
	const	std::string	&getType();
	void	setType(std::string type);

	private:

	std::string	_type;

};

#endif
