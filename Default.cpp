#include "Defaults.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Defaults::Defaults() {
	std::cout << "Defaults: default constructor called" << std::endl;
}

Defaults::Defaults(const Defaults &other) {
	std::cout << "Defaults: copy constructor called" << std::endl;
}

Defaults::~Defaults() {
	std::cout << "Defaults: default destructor called" << std::endl;
}

Defaults &Defaults::operator=(const Defaults &other) {
	std::cout << "Defaults: assigment operator called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/
