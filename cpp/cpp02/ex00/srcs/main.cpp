#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed a;
	a.setRawBits(3);
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << a.getRawBits() << std::endl;
	return (0);
}
