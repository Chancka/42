#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Assignation constructor called for Brain" << std::endl;
	for(int i; i < this->_nb_idea; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

