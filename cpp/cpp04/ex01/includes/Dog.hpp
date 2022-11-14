#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:

	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual Animal	&operator=(const Animal &other);
	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	private:

	Brain	*_brain;

};

#endif
