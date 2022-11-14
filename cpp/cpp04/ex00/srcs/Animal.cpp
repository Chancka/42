#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called for Animal" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Assignation constructor called for Animal" << std::endl;
	this->_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Sound of an Animal" << std::endl;
}

std::string	const Animal::getType() const
{
	return (_type);
}
