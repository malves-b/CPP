#pragma once

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(void);
	~Weapon();

	std::string	getType();
};

