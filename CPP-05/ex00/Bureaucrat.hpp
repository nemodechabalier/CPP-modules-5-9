#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <climits>


class Bureaucrat
{
private:

	const std::string _name;
	int _grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade()const;

	void incrementGrade(unsigned int value);
	void decrementGrade(unsigned int value);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what()const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
