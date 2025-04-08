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
	Fixed& operator++();
	Fixed Fixed::operator++(int);


	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	
	const Fixed& Fixed::min(const Fixed& a, const Fixed& b);
	const Fixed& Fixed::max(const Fixed& a, const Fixed& b);

};




#endif