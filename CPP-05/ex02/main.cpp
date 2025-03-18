#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("Thomas", 150);
	ShrubberyCreationForm S("crimas trees","trees");
	RobotomyRequestForm R("no idea","Wall-E");
	PresidentialPardonForm P("no idea", "Wall-E");
	std::cout << std::endl << std::endl;
	try {
		std::cout << b << std::endl;
		//b.decrementGrade(1);
		//R.beSigned(b);
		//P.beSigned(b);
		//S.beSigned(b);
		//S.beSigned(b);
		//S.execute(b);
		//b.executeForm(S);
		b.incrementGrade(149);
		S.execute(b);
		P.execute(b);
		R.execute(b);
		S.beSigned(b);
		P.beSigned(b);
		R.beSigned(b);
		b.executeForm(R);
		S.execute(b);
		R.execute(b);
		P.execute(b);
		std::cout << b << std::endl;
		//b.incrementGrade(1);
		//b.incrementGrade(2147483648);
		//Bureaucrat c("test", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	return (0);
}