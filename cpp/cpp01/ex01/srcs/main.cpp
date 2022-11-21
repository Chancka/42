#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(3, "test"); // 3 zombies with name "test"

	for (int i = 0; i < 3; i++)
		horde[i].announce(); // announce all zombies
	delete [] horde; // delete the horde
	return (0);	
}
