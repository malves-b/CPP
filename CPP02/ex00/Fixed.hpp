#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	static const int	fracBits = 8;
	int			rawBits;
public:
	Fixed(Fixed &a);
	Fixed(void);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
