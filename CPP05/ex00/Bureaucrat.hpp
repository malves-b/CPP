#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[1;34m"
#define yellow	"\033[33m"


class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	std::string getName();
	int			getGrade();

	void	increment();
	void	decrement();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
