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

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation constructor called for Fixed" << std::endl;
	this->_nb_fixed = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const	Fixed &rhs) const
{
	std::cout << "operator > constructor called for Fixed" << std::endl;
	return (this->_nb_fixed > rhs._nb_fixed);
}

bool	Fixed::operator<(const	Fixed &rhs) const
{
	std::cout << "operator < constructor called for Fixed" << std::endl;
	return (this->_nb_fixed < rhs._nb_fixed);
}

bool	Fixed::operator>=(const	Fixed &rhs) const
{
	std::cout << "operator >= constructor called for Fixed" << std::endl;
	return (this->_nb_fixed >= rhs._nb_fixed);
}

bool	Fixed::operator<=(const	Fixed &rhs) const
{
	std::cout << "operator <= constructor called for Fixed" << std::endl;
	return (this->_nb_fixed <= rhs._nb_fixed);
}

bool	Fixed::operator==(const	Fixed &rhs) const
{
	std::cout << "operator == constructor called for Fixed" << std::endl;
	return (this->_nb_fixed == rhs._nb_fixed);
}

bool	Fixed::operator!=(const	Fixed &rhs) const
{
	std::cout << "operator != constructor called for Fixed" << std::endl;
	return (this->_nb_fixed != rhs._nb_fixed);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->_nb_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed = *this;
	
	this->_nb_fixed++;
	return (fixed);
}

Fixed	&Fixed::operator--()
{
	this->_nb_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed = *this;

	this->_nb_fixed--;
	return (fixed);
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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
