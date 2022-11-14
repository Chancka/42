#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
	public:

	AAnimal();
	AAnimal(const AAnimal &other);
	virtual AAnimal &operator=(const AAnimal &other) = 0;
	virtual ~AAnimal();

	virtual void		makeSound() const = 0;
	std::string	const	getType() const;
	virtual Brain		*getBrain() const = 0;

	protected:

	std::string	_type;
};

#endif
