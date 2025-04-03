#include "Fixed.hpp"


Fixed::Fixed(){this->fix_point = 0;}
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}


int Fixed::getRawBits(void) const
{
	return 0;
}

void Fixed::setRawBits(int const raw)
{
}
