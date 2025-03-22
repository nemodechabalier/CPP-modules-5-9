#include "ScalarConverter.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter: default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	if (this != &other) {
		std::cout << "";
	}
	std::cout << "ScalarConverter: copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter: default destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		std::cout << "";
	}
	std::cout << "ScalarConverter: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void printImpossible() {
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
}

bool isDoubleOverflow(const std::string& type) {
	double d = strtod(type.c_str(), NULL);
	if (std::isinf(d) || std::isnan(d)) {
		return true;
	}
	if (d > std::numeric_limits<double>::max() ||
		d < -std::numeric_limits<double>::max()) {
		return true;
	}
	return false;
}

bool isInteger(const std::string& type) {
	if (type.empty())
		return false;
	size_t start = 0;
	if (type[0] == '+' || type[0] == '-')
		start = 1;
	if (start == 1 && type.length() == 1)
		return false;
	for (size_t i = start; i < type.length(); i++) {
		if (!isdigit(type[i]))
			return false;
	}
	return true;
}

bool isFloat(const std::string& type) {
	if (type[type.length() - 1] != 'f')
		return false;
	int start = 0;
	bool point = false;
	if (type[0] == '+' or type[0] == '-')
		start = 1;
	for (size_t i = start; i < type.length() - 1; i++) {
		if (!isdigit(type[i]) && type[i] != '.')
			return false;
		else if (type[i] == '.' && point == false)
			point = true;
		else if (type[i] == '.' && point == true)
			return false;
	}
	if (point)
		return true;
	return false;
}

bool isDouble(const std::string& type) {
	int start = 0;
	bool point = false;
	if (type[0] == '+' or type[0] == '-')
		start = 1;
	for (size_t i = start; i < type.length(); i++) {
		if (!isdigit(type[i]) && type[i] != '.')
			return false;
		else if (type[i] == '.' && point == false)
			point = true;
		else if (type[i] == '.' && point == true)
			return false;
	}
	if (point)
		return true;
	return false;
}

void convertChar(const std::string& type) {
	char c = type[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	if (isprint(c))
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertInt(const std::string& type) {
	if (isDoubleOverflow(type))
		return printImpossible();
	long l = std::atol(type.c_str());
	if (l > std::numeric_limits<int>::max() or l < std::numeric_limits<int>::min()) {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
	}
	else {
		int i = l;
		if (i >= CHAR_MIN and i <= CHAR_MAX) {
			char c = static_cast<char>(i);
			if (isprint(c))
				std::cout << "char : " << c << std::endl;
			else
				std::cout << "char : Non displayable" << std::endl;
		}
		else
			std::cout << "char : impossible" << std::endl;
		std::cout << "int : " << i << std::endl;

	}
	double d = std::strtod(type.c_str(), NULL);
	float f = static_cast<float>(d);
	if (d > std::numeric_limits<float>::max() or d < -std::numeric_limits<float>::max() + 1) {
		std::cout << "float : impossible" << std::endl;
	}
	else
		std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertDouble(const std::string& type) {
	if (isDoubleOverflow(type))
		return printImpossible();
	double d = std::strtod(type.c_str(), NULL);
	if (d < std::numeric_limits<int>::max() or d < std::numeric_limits<int>::min())
		return convertInt(type);
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	float f = static_cast<float>(d);
	if (d > std::numeric_limits<float>::max() or d < -std::numeric_limits<float>::max() + 1) {
		std::cout << "float : impossible" << std::endl;
	}
	else
		std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertFloat(const std::string& type) {
	std::string new_type = type;
	new_type[new_type.length() - 1] = 0;
	convertDouble(new_type);
}

void ScalarConverter::convert(const std::string& type) {
	if (type.empty()) {
		std::cout << "error can't be empty !!" << std::endl;
		return;
	}
	if (type.length() == 1 and not isdigit(type[0]))
		return convertChar(type);
	if (isInteger(type))
		return convertInt(type);
	if (isFloat(type))
		return convertFloat(type);
	if (isDouble(type))
		return convertDouble(type);
	if (type == "nanf" || type == "nan") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
		return;
	}
	if (type == "+inf" || type == "+inff" || type == "inf" || type == "inff")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
		return;
	}
	if (type == "-inf" || type == "-inff") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
	else
		std::cout << "Error worng input !!" << std::endl;
}