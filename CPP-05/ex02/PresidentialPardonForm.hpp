#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include <fstream>


class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& name, const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void execute(Bureaucrat const& executor) const;
};
