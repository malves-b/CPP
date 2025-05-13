#include "Bureaucrat.hpp"

Bureaucraut::Bureaucraut(/* args */)
{
}

Bureaucraut::~Bureaucraut()
{
}

std::string Bureaucraut::getName(){return this->name;}

int Bureaucraut::getGrade(){return this->grade;}

std::ostream &Bureaucraut::operator<<(const Bureaucraut &obj)
{
	std::cout << this->name << ", bureaucrat grade " << this->grade << std::endl;
}
