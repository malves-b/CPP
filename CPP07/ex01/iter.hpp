#if !defined ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(const T element){
	std::cout << element << std::endl;
}

template <typename T, typename Func>
void iter(T *addr, int len, Func func)
{
	for (int i = 0; i < len; i++){
		func(addr[i]);
	}
}

#endif // ITER_HPP
