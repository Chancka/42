#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor called for AMateria" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy constructor called for AMateria" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "Assignation constructor called for AMateria" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor of AMateria called" << std::endl;
}

