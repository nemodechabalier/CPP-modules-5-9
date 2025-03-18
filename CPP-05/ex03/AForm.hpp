#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include "Bureaucrat.hpp"

class Bureaucrat;


class AForm
{
private:

	std::string const _name;
	bool _signed;
	const int _gradeToExecute;
	const int _gradeToSigned;

public:
	AForm();
	AForm(const AForm& other);
	AForm(const std::string name, const int Signed, const int Execute);
	virtual ~AForm();
	AForm& operator=(const AForm& other);

	const std::string& getName()const;
	const int& getGradeToSign()const;
	const int& getGradeToExecute()const;
	const bool& getIsSigned()const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what()const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what()const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
