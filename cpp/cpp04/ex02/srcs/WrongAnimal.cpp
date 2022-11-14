#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Assignation constructor called for WrongAnimal" << std::endl;
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Sound of an Animal" << std::endl;
}

std::string	const WrongAnimal::getType() const
{
	return (_type);
}
