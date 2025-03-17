#include "Defaults.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Defaults::Defaults() {
	std::cout << "default constructor called" << std::endl;
}

Defaults::Defaults(const Defaults &other) {
	std::cout << "copy constructor called" << std::endl;
}

Defaults::~Defaults() {
	std::cout << "default destructor called" << std::endl;
}

Defaults &Defaults::operator=(const Defaults &other) {
	std::cout << "assigment operator called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/
