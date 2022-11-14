#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:

	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual AAnimal	&operator=(const AAnimal &other);
	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	private:

	Brain	*_brain;

};

#endif
