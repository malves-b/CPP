#include "Form.hpp"
#include "Bureaucrat.hpp"

//Default constructor
Form::Form(): _name("default"), _signGrade(1), _exeGrade(1){}

//Parametized constructor
Form::Form(std::string name, const int signGrade, const int exeGrade): _name(name), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (this->_exeGrade < 1 || this->_signGrade < 1)
		throw GradeTooHighException();
	if (this->_exeGrade > 150 || this->_signGrade > 150)
		throw GradeTooLowException();
}

//Copy constructor
Form::Form(const Form &cpy): _name(cpy._name), _signGrade(cpy._signGrade), _exeGrade(cpy._exeGrade){*this = cpy;}

//Destructor
Form::~Form(){std::cout << _name << " destroyed" << std::endl;}

//Operator overload
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

const char *Form::GradeTooLowException::what() const throw(){return "Grade is too low";}

const char *Form::GradeTooHighException::what() const throw(){return "Grade is too high";}

std::string Form::getName(){return this->_name;}

bool Form::getIsSigned(){return (this->_signed == true) ? true : false;}

int Form::getExeGrade(){return this->_exeGrade;}

int Form::getSignGrade(){return this->_signGrade;}

void Form::beSigned(Bureaucrat &brc)
{
	if (brc.getGrade() > this->getSignGrade()){
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form &obj)
{
	os << obj.getName() << "-> " <<
	"grade to execute: " << obj.getExeGrade() <<
	" | grade to sign: " << obj.getSignGrade() << std::endl;
	return os;
}
