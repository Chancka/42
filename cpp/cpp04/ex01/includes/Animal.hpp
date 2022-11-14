#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	public:

	Animal();
	Animal(const Animal &other);
	virtual Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void		makeSound() const;
	std::string	const	getType() const;
	virtual Brain		*getBrain() const = 0;

	protected:

	std::string	_type;
};

#endif
