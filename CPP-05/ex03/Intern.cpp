#include "Intern.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Intern::Intern() {
	std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	if (this != &other) {
		std::cout << "";
	}
	std::cout << "Intern: copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern: default destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		std::cout << "";
	}
	std::cout << "Intern: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

AForm* Intern::makeForm(const std::string& request, const std::string target) {
	static const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	int formIdx = -1;
	for (int i = 0; i < 3; i++) {
		if (request == formNames[i]) {
			formIdx = i;
			break;
		}
	}
	switch (formIdx)
	{
	case 0:
		return new ShrubberyCreationForm("default name", target);
	case 1:
		return new RobotomyRequestForm("default name", target);
	case 2:
		return new PresidentialPardonForm("default name", target);
	default:
		std::cerr << "Error: Form " << request << "' not found" << std::endl;
		break;
	}
	return NULL;
}
