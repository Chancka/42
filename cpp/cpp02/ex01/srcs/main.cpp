#include "../includes/Fixed.hpp"

int main(void)
{
	Fixed a; // Default constructor called for Fixed
	Fixed const b(10); // Int constructor called
	Fixed const c(42.42f); // Float constructor called
	Fixed const d(b); // Copy constructor called for Fixed

	a = Fixed(1234.4321f); // Assignation constructor called for Fixed
	
	std::cout << "a is " << a << std::endl; // << operator called
	std::cout << "b is " << b << std::endl; // << operator called
	std::cout << "c is " << c << std::endl; // << operator called
	std::cout << "d is " << d << std::endl; // << operator called

	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // toInt member function called
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // toInt member function called
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // toInt member function called
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // toInt member function called
	
	return 0;
}
