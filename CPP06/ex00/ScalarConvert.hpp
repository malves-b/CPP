#if !defined(MACRO)
#define MACRO

#include <string>
#include <iostream>

class ScalarConvert
{
private:
	ScalarConvert();
	ScalarConvert(const ScalarConvert &other);
	~ScalarConvert();

	ScalarConvert &operator=(const ScalarConvert &other);
public:
	static void convert(const std::string &str);

	class ConversionError : public std::exception{
	public:
		const char *what() const noexcept override	{
			return "Conversion error occurred";}
	};
};

#endif // MACRO