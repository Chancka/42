#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) // N is the number of zombies
{
	Zombie *horde = new Zombie[N]; // create a horde of N zombies

	for (int i = 0; i < N; i++)
		horde[i].named(name); // set the name of the zombies
	return (horde); // return the horde
}

