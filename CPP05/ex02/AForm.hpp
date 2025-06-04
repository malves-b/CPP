#pragma once

#include <iostream>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define blue	"\033[1;34m"
#define yellow	"\033[33m"

class Bureaucrat;

class AForm
{
private:
	const		std::string _name;
	bool		_signed;
	const int	_signGrade;
	const int	_exeGrade;
public:
	AForm();
	AForm(std::string name, const int signGrade, const int exeGrade);
	AForm(const AForm& cpy);
	virtual ~AForm();

	AForm&	operator=(const AForm &other);

	std::string getName() const;
	bool		getIsSigned() const ;
	int			getExeGrade() const ;
	int			getSignGrade() const ;

	void		beSigned(Bureaucrat &executor);

	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm& obj);
