#include "Animals.hpp"

//Default constructor
Cat::Cat(void): Animal("Cat"){
	identify();
	std::cout << "Default constructor" << std::endl;
	this->CatBrain = new Brain();
}

//Copy constructor
Cat::Cat(const Cat &cpy){
	identify();
	std::cout << "Copy constructor called" << std::endl;
	this->CatBrain = new Brain(*cpy.CatBrain);//deep copy
}

//Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	identify();
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->CatBrain;
		this->CatBrain = new Brain(*other.CatBrain);
	}
	return *this;
}

//Destructor
Cat::~Cat(){
	delete this->CatBrain;
	identify();
	std::cout << "Destroyed" << std::endl;
}

void Cat::makeSound(void)const
{
	std::cout << red << "--- Miau! ---" << reset << std::endl;
}
