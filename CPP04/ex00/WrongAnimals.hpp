#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	~WrongAnimal();
	std::string getType() const;
	void makeSound() const;
};

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	void makeSound() const;
};
