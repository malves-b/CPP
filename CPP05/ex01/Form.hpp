#pragma once

#include "Bureaucrat.hpp"

class Form
{
private:
	const	std::string name;
	bool	
public:
	Form();
	Form(std::string name);
	Form(const Form& cpy);
	~Form();

	Form&	operator=(const Form &other);


};

