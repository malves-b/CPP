#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[1;34m"
#define yellow	"\033[33m"

class GradeTooHighException : public std::exception
{
public:
	const char* what() const throw(){
		return "Grade is too high";}
};

class GradeTooLowException : public std::exception{
public:
	const char* what() const throw(){
		return "Grade is too low";}
};

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(std::string name, int grade);

	std::string getName();
	int			getGrade();

	Bureaucrat	increment();
	Bureaucrat	decrement();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
