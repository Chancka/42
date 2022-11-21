#include "../includes/Zombie.hpp"

Zombie*	newZombie(std::string name) // create a zombie on the heap and return a pointer to it
{
	return (new Zombie(name));
}
