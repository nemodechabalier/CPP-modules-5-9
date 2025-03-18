#include "Form.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Form::Form() :_name("default name"), _signed(false), _gradeToExecute(60), _gradeToSigned(30) {
	std::cout << "default constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToExecute(other._gradeToExecute), _gradeToSigned(other._gradeToSigned) {
	std::cout << "copy constructor called" << std::endl;
}

Form::Form(const std::string name, const int Signed, const int Execute) : _name(name), _signed(false),_gradeToExecute(Execute), _gradeToSigned(Signed)  {
	if (Signed > 150 || Execute > 150) {
		throw GradeTooLowException();
	}
	else if (Signed < 1 || Execute < 1) {
		throw GradeTooHighException();
	}
	std::cout << "custom constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "default destructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		//_name = other._name; 
		_signed = other._signed;
		//_gradeToExecute = _gradeToExecute;
		//_gradeToSigned = other._gradeToSigned;
	}
	std::cout << "assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/

const std::string& Form::getName()const {
	return _name;
}

const int& Form::getGradeToSign()const {
	return _gradeToSigned;
}

const int& Form::getGradeToExecute()const {
	return _gradeToExecute;
}

const bool& Form::getIsSigned()const {
	return _signed;
}

/* ............................................ FUNCTIONS .........................................................*/


const char* Form::GradeTooHighException::what() const throw() {
	return ("Form: grade too hight");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form: grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out  <<"[FORM_NAME]: " << f.getName() << std::endl;
	out  << "[GRADE_EXEC]: " <<f.getGradeToExecute() << std::endl;
	out  << "[GRADE_SIGN]: " <<f.getGradeToSign() << std::endl;
	out  << "[IS_SIGN]: " << f.getIsSigned() << std::endl;
	return out;
}

void Form::beSigned(const Bureaucrat &b) {
	if (_signed) {
		std::cout << "Form : " << _name << "has been already signed" << std::endl;
	}
	if (b.getGrade() < _gradeToSigned) {
		_signed = true;
		std::cout << "Congratulaion Bureaucrat " << b.getName() << " signed the Form " << _name << std::endl;
	}
	else
		throw GradeTooLowException();
}