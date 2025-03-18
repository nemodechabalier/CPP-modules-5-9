#include "RobotomyRequestForm.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("default_name", 72, 45) {
	_target = "default target";
	std::cout << "RobotomyRequestForm: default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target) : AForm(name, 72, 45) {
	_target = target;
	std::cout << "RobotomyRequestForm: custom constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	_target = other._target;
	std::cout << "RobotomyRequestForm: copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: default destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		std::cout << "Error RobotomyRequestForm : " << getName() << " is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
		return;
	}
	if (std::rand() % 2 == 0)
		std::cout << "RobotomyRequestForm : " << getName() << " has succeeded to robotomy " << _target << std::endl;
	else
		std::cout << "RobotomyRequestForm : " << getName() << " failed to robotomy " << _target << std::endl;

}