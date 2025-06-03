#if !defined INTERN
#define INTERN

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	AForm	*makeForm(std::string formName, std::string target);
};



#endif // INTERN

