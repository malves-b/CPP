#include "Animals.hpp"
#include "WrongAnimals.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;


	std::cout << yellow << "\n----- Wrong Animals -----" << reset << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;

	wrongCat->makeSound();
	wrong->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}