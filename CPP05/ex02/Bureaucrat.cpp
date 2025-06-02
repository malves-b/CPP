#include "Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() : name("default"), grade(150){
	std::cout << "Default Bureaucrat created" << std::endl;
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name){
	this->grade = other.grade;
}

//Paramized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
	std::cout << this->name << " Bureaucrat created" << std::endl;
}

//Destructor
Bureaucrat::~Bureaucrat(){std::cout << this->name << " Destroyed" << std::endl;}

//Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		const_cast<std::string&>(this->name) = other.name;
		this->grade = other.grade;
	}
	return *this;	
}

std::string Bureaucrat::getName(){return this->name;}

int Bureaucrat::getGrade() const {return this->grade;}

void	Bureaucrat::increment()
{
	if ((getGrade() - 1) < 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement()
{
	if ((getGrade() - 1) > 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
	obj.getName();
	os << obj.getName() << ": bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &frm)
{
	if (frm.getIsSigned()){
		std::cout << this->getName() << ": The form is already signed." << std::endl;
		return;
	}
	try
	{
		frm.beSigned(*this);
		std::cout << this->getName() << " signed " << frm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " <<
		frm.getName() << " because " << e.what() << '\n';
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){return "Grade is too low";}

const char *Bureaucrat::GradeTooHighException::what() const throw(){return "Grade is too high";}
