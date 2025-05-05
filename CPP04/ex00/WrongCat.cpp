#include "WrongAnimals.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructed\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound() const {
	std::cout << "--- Wrong Miau? ---\n";
}
