#include "Animals.hpp"

void Animal::identify()
{
	if (this->type == "Cat")
		std::cout << red << "	Cat: " << reset;
	else if (this->type == "Dog")
		std::cout << green << "	Dog: " << reset;
	else
		std::cout << yellow << "Animal: " << reset;
}

//Default constructor
Animal::Animal(void)
{
	identify();
	std::cout << "Default constructor" << std::endl;
	this->type = "Default";
}

//String constructor
Animal::Animal(std::string type)
{
	identify();
	std::cout << "Type constructor" << std::endl;
	this->type = type;
}

//Copy constructor
Animal::Animal(const Animal &cpy)
{
	identify();
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

//Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	identify();
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

//Destructor
Animal::~Animal(){
	std::cout << yellow << "Animal: " << reset "Destructor called" << std::endl;
}

std::string Animal::getType(void)const{return std::string(this->type);}
