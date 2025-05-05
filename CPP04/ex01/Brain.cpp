#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "		Brain: Constructor called" << std::endl;
}

Brain::Brain(Brain &cpy)
{
	std::cout << "		Brain: Copy constructor called" << std::endl;
	*this = cpy;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "		Brain: copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "		Brain Destroyed" << std::endl;
}
