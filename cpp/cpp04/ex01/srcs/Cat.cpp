#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
	this->_type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Assignation constructor called for Cat" << std::endl;
	*(this->_brain) = *(other.getBrain());
	return (*this);
}

Animal &Cat::operator=(const Animal &other)
{
	std::cout << "Animal assignation constructor called for Cat" << std::endl;
	*(this->_brain) = *(other.getBrain());
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor of Cat called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}
