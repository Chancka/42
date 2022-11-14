#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:

	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	virtual Animal	&operator=(const Animal &other);
	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	private:

	Brain	*_brain;


};

#endif
