#include "AForm.hpp"
class Bureaucrat;


/* ............................................ORTHODOX CANONICAL AForm ............................................*/

AForm::AForm() :_name("default name"), _signed(false), _gradeToExecute(60), _gradeToSigned(30) {
	std::cout << "default constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToExecute(other._gradeToExecute), _gradeToSigned(other._gradeToSigned) {
	std::cout << "copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int Signed, const int Execute) : _name(name), _signed(false), _gradeToExecute(Execute), _gradeToSigned(Signed) {
	if (Signed > 150 || Execute > 150) {
		throw GradeTooLowException();
	}
	else if (Signed < 1 || Execute < 1) {
		throw GradeTooHighException();
	}
	std::cout << "custom constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "default destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
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

const std::string& AForm::getName()const {
	return _name;
}

const int& AForm::getGradeToSign()const {
	return _gradeToSigned;
}

const int& AForm::getGradeToExecute()const {
	return _gradeToExecute;
}

const bool& AForm::getIsSigned()const {
	return _signed;
}

/* ............................................ FUNCTIONS .........................................................*/


const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm: grade too hight");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm: grade too low");
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
	out << "[AForm_NAME]: " << f.getName() << std::endl;
	out << "[GRADE_EXEC]: " << f.getGradeToExecute() << std::endl;
	out << "[GRADE_SIGN]: " << f.getGradeToSign() << std::endl;
	out << "[IS_SIGN]: " << f.getIsSigned() << std::endl;
	return out;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() < _gradeToSigned) {
		_signed = true;
		std::cout << _name << " is now signed" << std::endl;
	}
	else
		throw GradeTooLowException();
}

//void AForm::execute(Bureaucrat const& b) {

//}