#if !defined SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

#define INT_MAX		std::numeric_limits<int>::max()
#define INT_MIN		std::numeric_limits<int>::min()
#define FLOAT_MAX	std::numeric_limits<float>::max()
#define FLOAT_MIN	std::numeric_limits<float>::min()
#define DOUBLE_MAX	std::numeric_limits<double>::max()
#define DOUBLE_MIN	std::numeric_limits<double>::min()

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &other);

	static	void	charManagement(char c);
	static	void	intManagement(const int nbr);
	static	void	floatManagement(const float nbr);
	static	void	doubleManagement(const double nbr);
public:
	static void convert(const std::string &str);

	class ConversionError : public std::exception
	{
		public:
			virtual const char *what() const throw ();
	};
};

#endif // SCALAR_CONVERTER
