#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

#define NB_ANIMAL 8

int main()
{
	AAnimal	*animals[NB_ANIMAL];
	Brain	*brain;

	for (int i = 0; i < NB_ANIMAL; i++)
	{
		if (i < NB_ANIMAL / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < NB_ANIMAL; i++)
		std::cout << i << " " << animals[i]->getType() << std::endl;

	brain = animals[7]->getBrain();
	brain->ideas[0] = "I'm hungry";
	brain->ideas[1] = "That's a strange idea I'm having";
	brain->ideas[2] = "Ball!!!!!";
	brain->ideas[3] = "Squirrel!!!!!";
	std::cout << animals[7]->getType() << " " << animals[7]->getBrain()->ideas[0] << std::endl;

	*(animals[5]) = *(animals[7]);
	std::cout << animals[5]->getType() << " " << animals[5]->getBrain()->ideas[2] << std::endl;

	for (int i = 0; i < NB_ANIMAL; i++)
		delete animals[i];
}
