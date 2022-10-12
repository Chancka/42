#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i; i < N; i++)
		horde[i].named(name);
	return (horde);
}
