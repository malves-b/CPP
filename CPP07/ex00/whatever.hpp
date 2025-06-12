#if !defined TEMP_HPP
#define TEMP_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b){
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

#endif // TEMP_HPP
