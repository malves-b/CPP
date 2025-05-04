#include "Cat.hpp"

//Default constructor
Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat: Default constructor" << std::endl;
}

//Copt constructor
Cat::Cat(const Cat &cpy)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = cpy;	
}

//Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

//Destructor
Cat::~Cat(){std::cout << getType() << " Destroyed" << std::endl;}

void Cat::makeSound(void)const
{
	std::cout << red << "--- Miau! ---" << reset << std::endl;
}
