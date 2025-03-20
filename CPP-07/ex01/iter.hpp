#pragma once


#include <string>
#include <iostream>

template <typename T>
void iter(T* tab_ptr, T len, T function) {
	for (int i = 0; i < len;i++)
		function(tab_ptr[i]);
}
