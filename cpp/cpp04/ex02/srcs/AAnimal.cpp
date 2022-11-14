#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Default constructor called for AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Copy constructor called for AAnimal" << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Assignation constructor called for AAnimal" << std::endl;
	this->_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor of AAnimal called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "Sound of an AAnimal" << std::endl;
}

std::string	const AAnimal::getType() const
{
	return (_type);
}
