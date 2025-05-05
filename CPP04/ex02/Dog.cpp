#include "Animals.hpp"

//Default constructor
Dog::Dog(void): Animal("Dog")
{
	identify();
	std::cout << "Default constructor" << std::endl;
	this->DogBrain = new Brain();
}

//Copy constructor
Dog::Dog(const Dog &cpy)
{
	identify();
	std::cout << "Copy constructor called" << std::endl;
	this->DogBrain = new Brain(*cpy.DogBrain);//deep copy
}

//Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	identify();
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->DogBrain;
		this->DogBrain = new Brain(*other.DogBrain);
	}
	return *this;
}

//Destructor
Dog::~Dog(){
	delete this->DogBrain;
	identify();
	std::cout  << "Destroyed" << std::endl;
}

void Dog::makeSound(void)const
{
	std::cout << red << "--- AU AU! ---" << reset << std::endl;
}