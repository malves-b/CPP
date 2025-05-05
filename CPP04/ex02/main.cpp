#include "Animals.hpp"

int main() {
    Animal* arr[6];

    for (size_t i = 0; i < 6; i++) {
        if (i < 3)
            arr[i] = new Cat();
        else
            arr[i] = new Dog();
    }

	for (size_t i = 0; i < 6; i++)
		arr[i]->makeSound();
	

    for (size_t i = 0; i < 6; i++) {
        delete arr[i];
    }

	// Animal *test = Animal();

	// std::cout << "\n----------------------------------\n\n";

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;
	// delete i;
    return 0;
}
