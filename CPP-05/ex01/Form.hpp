#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include "Bureaucrat.hpp"

class Form
{
private:

	std::string const _name;
	bool _signed;
	const int _gradeToSigned;
	const int _gradeToExecute;

public:
	Form();
	Form(const Form& other);
	Form(const std::string name, const int Signed, const int Execute);
	~Form();
	Form& operator=(const Form& other);

	const std::string& getName()const;
	const int& getGradeToSign()const;
	const int& getGradeToExecute()const;
	const bool& getIsSigned()const;

	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what()const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &f);
