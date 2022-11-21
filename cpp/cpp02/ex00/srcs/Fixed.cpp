#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called for Fixed" << std::endl;
	this->_nb_fixed = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called for Fixed" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation constructor called for Fixed" << std::endl;
	this->_nb_fixed = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor of Fixed called" << std::endl;
}

int	Fixed::getRawBits(void) const // return the value of the fixed point value
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb_fixed);
}

void	Fixed::setRawBits(int const raw) // set the value of the fixed point value
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb_fixed = raw;
}
