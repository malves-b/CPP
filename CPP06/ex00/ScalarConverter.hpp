#if !defined SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

#define INT_MAX = std::numeric_limits<int>::max
#define INT_MIN = std::numeric_limits<int>::min

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &other);

	void	charManagement(std::string &str);
	void	intManagement(std::string &str);
	void	floatManagement(std::string &str);
	void	doubleManagement(std::string &str);

	void	setType(std::string &str);
public:
	static void convert(const std::string &str);

	class ConversionError : public std::exception{
	public:
		const char *what() const noexcept override	{
			return "Conversion error occurred";}
	};
};

// template <typename T>
// std::ostream& operator<<(std::ostream& os, T & type);

#endif // SCALAR_CONVERTER

// template <typename T>
// std::ostream &operator<<(std::ostream &os, T &type)
// {

// }
