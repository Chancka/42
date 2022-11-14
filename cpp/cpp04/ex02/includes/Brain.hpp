#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:

	static const int	_nb_idea = 100;

	public:

	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string	ideas[Brain::_nb_idea];

};

#endif
