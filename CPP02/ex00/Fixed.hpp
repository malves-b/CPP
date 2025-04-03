#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
	int			fix_point;
	static int	frac_bits;
public:
	Fixed(/* args */);
	Fixed(void);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
