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

//Exception
const char *ScalarConverter::ConversionError::what() const throw(){return "Conversion error occurred";}


void ScalarConverter::charManagement(char c)
{
	// std::cout << "\n ----- Convert from CHAR ----- \n\n";
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << '\n';
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << '\n';
}

void ScalarConverter::intManagement(const int nbr)
{
	// std::cout << "\n ----- Convert from INT ----- \n\n";
	if (nbr >= 0 && nbr <= 127){
		if (std::isprint(nbr))
			std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: impossible\n";}

	std::cout << "int: " << nbr << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(nbr) << "f\n";
	std::cout << "double: " << static_cast<double>(nbr) << "\n";
}

void ScalarConverter::floatManagement(const float nbr)
{
	// std::cout << "\n ----- Convert from FLOAT ----- \n\n";
	if (nbr >= 0 && nbr <= 127){
		if (std::isprint(nbr))
			std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: impossible\n";}
	if (nbr <= INT_MAX && nbr >= INT_MIN)
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
	else
		std::cout << "int: impossible\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << nbr << "f\n";
	std::cout << "double: " << nbr << "\n";
}

void ScalarConverter::doubleManagement(const double nbr)
{
	// std::cout << "\n ----- Convert from DOUBLE ----- \n\n";
	if (nbr >= 0 && nbr <= 127){
		if (std::isprint(nbr))
			std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: impossible\n";}

	if (nbr <= INT_MAX && nbr >= INT_MIN)
		std::cout << "int: " << static_cast<int>(nbr) << "\n";
	else
		std::cout << "int: impossible\n";

	std::cout << std::fixed << std::setprecision(1);
	if ((nbr <= FLOAT_MAX && nbr >= FLOAT_MIN) || std::isnan(nbr) || std::isinf(nbr))
		std::cout << "float: " << static_cast<float>(nbr) << "f\n";
	else
		std::cout << "float: impossible\n";
	std::cout << "double: " << nbr << "\n";
}

void ScalarConverter::convert(const std::string &str)
{
	//char
	if (str.length() == 1 && ((str[0] >= 0 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 126)))
		return charManagement(str[0]);

	char*	rest;
	
	//int
	long	nbr = std::strtol(str.c_str(), &rest, 10);
	if (str.find('.') == std::string::npos && nbr <= INT_MAX && nbr >= INT_MIN && !rest[0])	{
		return intManagement(std::atoi(str.c_str()));}

	//float
	std::strtof(str.c_str(), &rest);
	if ((rest[0] == ('f') && !rest[1]) || str == "-inff" || str == "+inff" || str == "nanf") {
		return floatManagement(std::atof(str.c_str()));}

	//double
	std::strtod(str.c_str(), &rest);
	if ((!rest[0] && nbr <= DOUBLE_MAX && nbr >= DOUBLE_MIN) || str == "nan" || str == "+inf" || str == "-inf")	{
		return doubleManagement(std::strtod(str.c_str(), NULL));}
}
