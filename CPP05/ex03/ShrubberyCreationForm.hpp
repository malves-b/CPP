#if !defined(SHRB_CREATION)
#define SHRB_CREATION

#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();
	
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	
	std::string	getTarget();
	
	void	execute(Bureaucrat const &executor) const;
};

#endif // SHRB_CREATION