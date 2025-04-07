#include "./Fixed.hpp"

Fixed::Fixed(Fixed &a)
{
	this->rawBits = a.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed()
{
	this->rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other){return *this;}
	this->rawBits = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return 0;
}

void Fixed::setRawBits(int const raw){this->rawBits = raw;}
