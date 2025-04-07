#include "./Fixed.hpp"

//Default constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

//Int constructor
Fixed::Fixed(int init)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = init << _fractionalBits;
}

//Float constructor
Fixed::Fixed(float init)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(init * (1 << _fractionalBits));
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other._fixedPointValue;
}


//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

//Destructor
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

int Fixed::toInt(void) const{
	return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
