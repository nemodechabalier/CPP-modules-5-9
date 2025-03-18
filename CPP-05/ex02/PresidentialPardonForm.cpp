#include "PresidentialPardonForm.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_name", 25, 5) {
	_target = "default target";
	std::cout << "PresidentialPardonForm: default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target) : AForm(name, 25, 5) {
	_target = target;
	std::cout << "PresidentialPardonForm: custom constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	_target = other._target;
	std::cout << "PresidentialPardonForm: copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: default destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	std::cout << "PresidentialPardonForm: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		std::cout << "Error PresidentialPardonForm : " << getName() << " is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
		return;
	}
	std::cout << "PresidentialPardonForm : " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}