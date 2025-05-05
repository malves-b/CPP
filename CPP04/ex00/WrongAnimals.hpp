#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	~WrongAnimal(); // opcional
	std::string getType() const;
	void makeSound() const; // NOT virtual
};

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	void makeSound() const;
};
