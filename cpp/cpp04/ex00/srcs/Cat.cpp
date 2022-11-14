#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	(void)other;
	std::cout << "Assignation constructor called for Cat" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
