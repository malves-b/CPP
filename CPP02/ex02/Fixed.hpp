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
	Fixed(Fixed& a1);
	Fixed(int nbr);
	Fixed(float nbr);

	~Fixed();

    Fixed &operator=(const Fixed& other);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
};

// Operadores de comp
// Fixed::bool operator>(const Fixed& other) const;
// bool operator+(const Fixed& other, int);
// bool operator>=(const Fixed& other) const;
// bool operator<=(const Fixed& other) const;
// bool operator==(const Fixed& other) const;
// bool operator!=(const Fixed& other) const;

//Operadores aritm
// Fixed operator+(const Fixed& other) const;
// Fixed operator-(const Fixed& other) const;
// Fixed operator*(const Fixed& other) const;
// Fixed operator/(const Fixed& other) const;

//Incremento/Decremento
int operator++(Fixed obj);
// Fixed& operator--();

#endif