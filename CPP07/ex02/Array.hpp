#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
private:
    T*		data;
    int		len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
	Array& operator=(const Array& other);
	
    ~Array() {delete[] data;}

    T& operator[](int index);
	const T& operator[](int index) const;

    int size() const {return len;}
};	

template <typename T>
Array<T>::Array(): data(nullptr), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(nullptr), len(other.len)
{
	data = new T[len];
	for (std::int i = 0; i < len; ++i)
	data[i] = other.data[i];
}	

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other) {
		delete[] data;
		len = other.len;
		data = new T[len];
		for (std::int i = 0; i < len; ++i)
			data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int index){
	if (index >= len)
		throw std::out_of_range("Index out of the bounds");
	return data[index];
}

template <typename T>
const T &Array<T>::operator[](int index) const{
	if (index >= len)
		throw std::out_of_range("Index out of the bounds");
	return data[index];	
}

#endif