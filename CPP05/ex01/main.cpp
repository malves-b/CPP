#include "Form.hpp"

int main()
{
	try
	{
		Form ze = Form("ze", 0, 30);
		std::cout << ze;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
