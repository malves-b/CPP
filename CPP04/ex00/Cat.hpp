#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &cpy);

	Cat &operator=(const Cat &other);

	~Cat();

	virtual void makeSound(void) const;
};
