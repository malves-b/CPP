#pragma once

#include <iostream>
#include <string>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[1;34m"
#define yellow	"\033[33m"

class Bureaucraut
{
private:
	const std::string name;
	int grade;
public:
	Bureaucraut(/* args */);
	~Bureaucraut();

	std::string getName();
	int			getGrade();

	std::ostream& operator<<(const Bureaucraut& obj);
};

