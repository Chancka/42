#include "../includes/Zombie.hpp"

int main(int ac, char **av)
{
	Zombie *horde = zombieHorde(std::stoi(av[1]), av[2]);

	for (int i; i < std::stoi(av[1]); i++)
		horde[i].announce();
	delete [] horde;
	return (0);	
}
