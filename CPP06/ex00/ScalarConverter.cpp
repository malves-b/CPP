#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(){}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other){*this = other;}

// Destructor
ScalarConverter::~ScalarConverter(){}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void	ScalarConverter::setType(std::string &str)
{
	//char
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return charManagement(str);

	long i = std::stol(str);
	//int
	if (i < )
	{
		
	}
	return 0;
}

void ScalarConverter::convert(const std::string &str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (str.empty())
		ConversionError();
	
	//from char
	if (str.length() != 1){

	}
	
	//from string
	if (){

	}

	//from int
	if ()
	{
		/* code */
	}
	
	//from float
	if (condition)
	{
		/* code */
	}
	
	//from double
	if (condition)
	{
		/* code */
	}
	
	std::cout << "char: "
	<< "\nint: "
	<< "\nfloat: "
	<< "\ndouble: ";
}
