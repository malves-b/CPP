#pragma once

#include <string>
#include <iostream>

#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[34m"
#define yellow	"\033[33m"
#define RESET	"\033[0m"

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl(void);
	~Harl();

	void	complain(std::string level);
};

