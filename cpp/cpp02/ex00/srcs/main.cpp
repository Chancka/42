#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed a; // Default constructor called for Fixed
	a.setRawBits(3); // setRawBits member function called
	Fixed b( a ); // Copy constructor called for Fixed
	Fixed c; // Default constructor called for Fixed
	c = b; // Assignation constructor called for Fixed
	std::cout << a.getRawBits() << std::endl; // getRawBits member function called
	std::cout << b.getRawBits() << std::endl; // getRawBits member function called
	std::cout << c.getRawBits() << std::endl; // getRawBits member function called
	std::cout << a.getRawBits() << std::endl; // getRawBits member function called
	return (0);
}
