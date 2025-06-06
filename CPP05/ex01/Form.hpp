#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const		std::string _name;
	bool		_signed;
	const int	_signGrade;
	const int	_exeGrade;
public:
	Form();
	Form(std::string name, const int signGrade, const int exeGrade);
	Form(const Form& cpy);
	~Form();

	Form&	operator=(const Form &other);

	std::string getName();
	bool		getIsSigned();
	int			getExeGrade();
	int			getSignGrade();

	void	beSigned(Bureaucrat &executor);


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

std::ostream& operator<<(std::ostream& os, Form& obj);
