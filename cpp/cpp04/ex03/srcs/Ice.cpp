#include "../includes/Ice.hpp"

Ice::Ice()
{
	std::cout << "Default constructor called for Ice" << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Copy constructor called for Ice" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Assignation constructor called for Ice" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor of Ice called" << std::endl;
}

