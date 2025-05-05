#include "Animals.hpp"

//Default constructor
Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog: Default constructor" << std::endl;
}

//Copt constructor
Dog::Dog(const Dog &cpy)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = cpy;	
}

//Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

//Destructor
Dog::~Dog(){std::cout << getType() << " Destroyed" << std::endl;}

void Dog::makeSound(void)const
{
	std::cout << red << "--- AU AU! ---" << reset << std::endl;
}