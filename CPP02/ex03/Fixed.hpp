#ifndef FIXED_02
# define FIXED_02

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
    static const int _fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& a1);
	Fixed(int nbr);
	Fixed(float nbr);

	~Fixed();

    Fixed &operator=(const Fixed& other);

	float toFloat(void) const;
	int	toInt(void) const;
	
	// Operadores de comp
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	
	//Operadores aritm
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	
	//Incremento/Decremento
	Fixed& operator--();
	Fixed operator--(int);
	Fixed& operator++();
	Fixed operator++(int);


	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif