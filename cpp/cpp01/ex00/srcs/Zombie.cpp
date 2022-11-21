#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string _name) : _name(_name)
{
	std::cout << "Constructor called" << std::endl;
	std::cout << this->_name << " created !" << std::endl;
}


Zombie::~Zombie()
{
	std::cout << "Destructor called" << std::endl;
	std::cout << this->_name << " died !" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
