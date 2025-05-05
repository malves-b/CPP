#pragma once

#include <iostream>
#include <string>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[1;34m"
#define yellow	"\033[33m"

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &cpy);
	Animal &operator=(const Animal &other);

	virtual ~Animal();

	std::string getType(void)const;
	virtual	void	makeSound() const;
};

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &cpy);
	Cat &operator=(const Cat &other);

	~Cat();
	virtual void makeSound(void) const;
};

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual void makeSound(void) const;
};