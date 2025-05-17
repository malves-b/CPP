#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try{
		if (grade > 150)
			throw GradeTooLowException();
		if (grade < 1)
			throw GradeTooHighException();
		this->grade = grade;
		std::cout << "Bureaucrat created" << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}

std::string Bureaucrat::getName(){return this->name;}

int Bureaucrat::getGrade(){return this->grade;}

Bureaucrat Bureaucrat::increment()
{
	if ((getGrade() - 1) < 1)
		throw GradeTooHighException();
	this->grade--;
	return *this;
}

Bureaucrat Bureaucrat::decrement()
{
	if ((getGrade() - 1) > 150)
		throw GradeTooLowException();
	this->grade++;
	return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
	obj.getName();
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
