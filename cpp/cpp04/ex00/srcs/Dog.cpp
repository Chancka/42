#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Assignation constructor called for Dog" << std::endl;
	(void)other;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}
