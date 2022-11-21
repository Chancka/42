#include "../includes/Zombie.hpp"

void	randomChump(std::string name) // create a zombie on the stack and call announce
{
	Zombie	chump(name);
	chump.announce();
}
