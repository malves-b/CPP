#if !defined EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found.");
    }
    return it;
}


#endif // EASYFIND_HPP