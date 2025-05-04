#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual void makeSound(void) const;
};

