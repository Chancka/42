#include "../includes/Zombie.hpp"

Zombie::Zombie() 
{
	std::cout << "Constructor of Zombie called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor of Zombie called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::named(std::string name)
{
	this->_name = name; // set the name of the zombie
}
