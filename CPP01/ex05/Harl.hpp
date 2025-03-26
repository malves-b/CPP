#pragma once

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define blue "\033[34m"
#define red		"\033[31m"
#define green	"\033[32m"
#define yellow	"\033[33m"

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl(/* args */);
	~Harl();

	void	complain(std::string level);
};
