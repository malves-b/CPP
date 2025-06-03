#if !definedPRES_PARDON
#define PRES_PARDON

#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	std::string _target;
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &cpy);
	~PresidentialPardonForm();
	
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	
	void	execute(Bureaucrat const &executor) const;
};

#endif // PRES_PARDON