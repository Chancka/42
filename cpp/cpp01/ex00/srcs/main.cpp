#include "../includes/Zombie.hpp"

int main(void)
{
	std::cout << "==========       CONSTRUCTOR      ==========" << std::endl << std::endl;
	Zombie	zombie_stack("Stackouille"); // Zombie on the stack
	Zombie*	zombie_heap = newZombie("Heapouille"); // newZombie is a function that creates a new Zombie on the heap and returns a pointer to it
	std::cout << std::endl;

	std::cout << "==========        ANNOUNCE        ==========" << std::endl << std::endl;
	zombie_stack.announce();
	zombie_heap->announce();	// same as (*zombie_heap).announce();
	delete zombie_heap; // delete the pointer
	std::cout << std::endl;

	std::cout << "==========   AWAKENING OF CHUMP   ==========" << std::endl << std::endl;
	randomChump("Chumpouille"); // create a zombie on the stack and call announce
	std::cout << std::endl;

	std::cout << "==========       DESTRUCTOR       ==========" << std::endl << std::endl;
	// Destructor called for zombie_stack because it is on the stack
	return (0);	
}
