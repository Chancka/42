#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called for Fixed" << std::endl;
	this->_nb_fixed = 0;
}

Fixed::Fixed(const int nb_int)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nb_fixed = nb_int << this->_bits;
}

Fixed::Fixed(const float nb_float)
{
	std::cout << "Default constructor called for Fixed" << std::endl;
	this->_nb_fixed = roundf(nb_float * (float)(1 << this->_bits));
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb_fixed = raw;
}

int		Fixed::toInt() const {

	return (this->_nb_fixed >> this->_bits);
}

float	Fixed::toFloat() const {

	return ((float) this->_nb_fixed / (float)(1 << this->_bits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
