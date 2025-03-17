#include "Bureaucrat.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Bureaucrat::Bureaucrat() : _name("default name"), _grade(150) {
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1) {
		_grade = 150;
		std::cout << "Error grade too low" << std::endl;
		throw GradeTooHighException();
	}
	if (grade > 150) {
		_grade = 150;
		std::cout << "Error grade too high" << std::endl;
		throw GradeTooLowException();
	}
	_grade = grade;
	std::cout << "custom constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "default destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "assigment operator called" << std::endl;
	if (this != &other) {
		std::cout << "error _name is const" << std::endl;
		//_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

/* ............................................ FUNCTIONS .........................................................*/


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getGrade();
	return out;
}


void Bureaucrat::incrementGrade(unsigned int value) {
	int new_grade = _grade - value;
	if (value > INT_MAX || new_grade > 150 || new_grade < 1) {
		throw GradeTooHighException();
	}
	else {
		_grade = new_grade;
		std::cout << "Congratulation : you lvl up !!" << std::endl;
	}
}

void Bureaucrat::decrementGrade(unsigned int value) {
	int new_grade = _grade + value;
	if (value > INT_MAX || new_grade > 150 || new_grade < 1) {
		throw GradeTooLowException();
	}
	else {
		_grade = new_grade;
		std::cout << "Oh no : you lvl down !!" << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: grade too hight");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: grade too low");
}