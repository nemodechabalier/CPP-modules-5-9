#include "Data.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Data::Data():_name("default"), _age(42) {
	std::cout << "Data: default constructor called" << std::endl;
}

Data::Data(const Data &other):_name(other._name), _age(other._age) {
	std::cout << "Data: copy constructor called" << std::endl;
}

Data::~Data() {
	std::cout << "Data: default destructor called" << std::endl;
}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		_name = other._name;
		_age = other._age;
	}
	std::cout << "Data: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

