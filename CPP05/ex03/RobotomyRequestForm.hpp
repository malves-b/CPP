#if !defined ROB_REQUEST
#define ROB_REQUEST

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& cpy);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void	execute(Bureaucrat const &executor) const;
};

#endif // ROB_REQUEST
