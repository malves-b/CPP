#include "WrongAnimals.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::WrongAnimal(std::string t) : type(t) {
	std::cout << "WrongAnimal constructed with type\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed\n";
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal: generic wrong sound\n";
}
