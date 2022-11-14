#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Assignation constructor called for Dog" << std::endl;
	*(this->_brain) = *(other.getBrain());
	return (*this);
}

Animal &Dog::operator=(const Animal &other)
{
	std::cout << "Animal assignation constructor called for Dog" << std::endl;
	*(this->_brain) = *(other.getBrain());
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}
