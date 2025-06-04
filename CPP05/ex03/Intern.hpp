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
	Intern(const Intern &cpy);
	Intern &operator=(const Intern &);
	~Intern();

	AForm	*makeForm(std::string formName, std::string target);

	class NotFoundException : public std::exception
	{
		private:
			std::string _message;
		public:
			NotFoundException(const std::string& formName);
			virtual ~NotFoundException() throw() {}
			virtual const char *what() const throw();
	};
};

#endif // INTERN
