#pragma once


#include <string>
#include <iostream>

template <typename T>
void iter(T* tab_ptr, size_t len, void (*func)(T&)) {
	for (size_t i = 0; i < len;i++)
		func(tab_ptr[i]);
}

template <typename T>
void iter(const T* tab_ptr, size_t len, void (*func)(const T&)) {
	for (size_t i = 0; i < len;i++)
		func(tab_ptr[i]);
}

template <typename T>
void printTemplate(T& t) {
	std::cout << t << std::endl;
}

template <typename T>
void increment(T& t) {
	t++;
}
