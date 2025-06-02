#pragma once

#include <iostream>

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
	~AForm();

	AForm&	operator=(const AForm &other);

	std::string getName();
	bool		getIsSigned() const ;
	int			getExeGrade() const ;
	int			getSignGrade() const ;

	void		beSigned(Bureaucrat &brc);

	virtual void	execute(Bureaucrat const &brc) const = 0;

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
