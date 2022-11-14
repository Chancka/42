#include "../includes/Cure.hpp"

Cure::Cure()
{
	std::cout << "Default constructor called for Cure" << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Copy constructor called for Cure" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Assignation constructor called for Cure" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor of Cure called" << std::endl;
}

