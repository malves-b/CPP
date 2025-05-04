#include "Animal.hpp"

//Default constructor
Animal::Animal(void)
{
	std::cout << "Animal: Default constructor" << std::endl;
	this->type = "Default";
}

//String constructor
Animal::Animal(std::string type)
{
	std::cout << "Animal: String constructor" << std::endl;
	this->type = type;
}

//Copy constructor
Animal::Animal(const Animal &cpy)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = cpy;
}

//Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Copy assignment operator" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

//Destructor
Animal::~Animal(){std::cout << "Animal: Destructor called" << std::endl;}

std::string Animal::getType(void)const{return std::string(this->type);}
