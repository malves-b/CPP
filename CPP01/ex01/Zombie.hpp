#pragma once

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define yellow	"\033[33m"

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie();
	void	set_name(std::string name);
	void	announce();
};

Zombie* zombieHorde(int N, std::string name);
