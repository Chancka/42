#include "../includes/Character.hpp"

Character::Character()
{
	std::cout << "Default constructor called for Character" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor called for Character" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Assignation constructor called for Character" << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor of Character called" << std::endl;
}

