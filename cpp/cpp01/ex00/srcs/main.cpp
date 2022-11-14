#include "../includes/Zombie.hpp"

int main(void)
{
	std::cout << "==========       CONSTRUCTOR      ==========" << std::endl << std::endl;
	Zombie	zombie_stack("Stackouille");
	Zombie*	zombie_heap = newZombie("Heapouille");
	std::cout << std::endl;

	std::cout << "==========        ANNOUNCE        ==========" << std::endl << std::endl;
	zombie_stack.announce();
	zombie_heap->announce();
	std::cout << std::endl;

	std::cout << "==========   AWAKENING OF CHUMP   ==========" << std::endl << std::endl;
	randomChump("Chumpouille");
	std::cout << std::endl;

	std::cout << "==========       DESTRUCTOR       ==========" << std::endl << std::endl;
	delete zombie_heap;
	return (0);	
}
