#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:

	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	virtual AAnimal	&operator=(const AAnimal &other);
	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	private:

	Brain	*_brain;


};

#endif
