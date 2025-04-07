#include "./Fixed.hpp"

//Default constructor
Fixed::Fixed(void)
{
	this->_fixedPointValue = 0;
}

//Copy constructor
Fixed::Fixed(Fixed& a1)
{
	this->_fixedPointValue = a1._fixedPointValue;
}

//Float constructor
Fixed::Fixed(const float value) {
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
	return ;
}

//Int constructor
Fixed::Fixed(const int value){
	this->_fixedPointValue = value << _fractionalBits;
}








Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedPointValue < b._fixedPointValue)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedPointValue > b._fixedPointValue)
		return a;
	return b;
}
