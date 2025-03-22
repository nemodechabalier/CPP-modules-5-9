#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class notFoundExeption : public std::exception {
public:
	virtual const char* what()const throw() {
		return "Error not found";
	};
};

template <typename T>
int easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	else
		throw notFoundExeption();

};

template <typename T>
int easyfind(const T& container, int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	else
		throw notFoundExeption();

};