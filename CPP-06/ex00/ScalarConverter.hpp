#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <climits>





class ScalarConverter
{
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);

public:
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(const std::string& type);
};