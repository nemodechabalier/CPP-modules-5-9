#pragma once

#include <string>
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& request, const std::string &target);

};
