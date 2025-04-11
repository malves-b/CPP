#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void)
{
	this->_fixedPointValue = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed& a1)
{
	this->_fixedPointValue = a1._fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
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

//Destructor
Fixed::~Fixed(){}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->_fixedPointValue > other._fixedPointValue)
		return true;
	return false;
}
bool Fixed::operator<(const Fixed &other) const
{
	if (this->_fixedPointValue < other._fixedPointValue)
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed &other)const
{
	if (this->_fixedPointValue >= other._fixedPointValue)
		return true;
	return false;
}
bool Fixed::operator<=(const Fixed &other)const
{
	if (this->_fixedPointValue <= other._fixedPointValue)
		return true;
	return false;
}
bool Fixed::operator==(const Fixed &other)const
{
	if (this->_fixedPointValue == other._fixedPointValue)
		return true;
	return false;
}
bool Fixed::operator!=(const Fixed &other)const
{
	if (this->_fixedPointValue != other._fixedPointValue)
		return true;
	return false;
}


Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0){
		std::cerr << "Error: Division by zero!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

/**/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed& Fixed::operator++(){
	this->_fixedPointValue++;
	return *this;
}
Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}
Fixed& Fixed::operator--(){
	this->_fixedPointValue--;
	return *this;
}
Fixed Fixed::operator--(int){
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){ return (a._fixedPointValue < b._fixedPointValue) ? a: b;}

Fixed &Fixed::max(Fixed &a, Fixed &b){return (a._fixedPointValue > b._fixedPointValue)? a : b;}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){return (a < b) ? a : b;}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){return (a > b) ? a : b;}
