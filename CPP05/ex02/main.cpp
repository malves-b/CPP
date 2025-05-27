#include "Bureaucrat.hpp"

int main()
{
	Form frm = Form("Form", 75, 5);

	Bureaucrat b1 =  Bureaucrat("B1", 74);
	Bureaucrat b2 =  Bureaucrat("B2", 76);

	std::cout << frm;
	std::cout << b1;
	std::cout << b2;

	b1.signForm(frm);
	b2.signForm(frm);
	return 0;
}
