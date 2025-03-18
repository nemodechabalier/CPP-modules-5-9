#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	//{
	//	Bureaucrat b("Thomas", 150);
	//	ShrubberyCreationForm S("crimas trees", "trees");
	//	RobotomyRequestForm R("no idea", "Wall-E");
	//	PresidentialPardonForm P("no idea", "Wall-E");
	//	std::cout << std::endl << std::endl;
	//	try {
	//		std::cout << b << std::endl;
	//		//b.decrementGrade(1);
	//		//R.beSigned(b);
	//		//P.beSigned(b);
	//		//S.beSigned(b);
	//		//S.beSigned(b);
	//		//S.execute(b);
	//		//b.executeForm(S);
	//		b.incrementGrade(149);
	//		S.execute(b);
	//		P.execute(b);
	//		R.execute(b);
	//		S.beSigned(b);
	//		P.beSigned(b);
	//		R.beSigned(b);
	//		b.executeForm(R);
	//		S.execute(b);
	//		R.execute(b);
	//		P.execute(b);
	//		std::cout << b << std::endl;
	//		//b.incrementGrade(1);
	//		//b.incrementGrade(2147483648);
	//		//Bureaucrat c("test", 151);
	//	}
	//	catch (std::exception& e) {
	//		std::cout << e.what() << std::endl;
	//	}
	//	std::cout << std::endl << std::endl;
	//}
	{
		Intern I;
		AForm* f1 = I.makeForm("shrubbery creation", "target");
		AForm* f2 = I.makeForm("robotomy request", "target");
		AForm* f3 = I.makeForm("presidential pardon", "target");
		AForm* f4 = I.makeForm("doesn't exist", "target");
		Bureaucrat b("bureau",1);

		std::cout << std::endl << std::endl;
		f1->beSigned(b);
		f2->beSigned(b);
		f3->beSigned(b);
		b.executeForm(*f1);
		b.executeForm(*f2);
		b.executeForm(*f3);
		if (f4 == NULL)
			std::cout << "f4 is NULL" << std::endl;
		std::cout << std::endl << std::endl;


		delete f1;
		delete f2;
		delete f3;
	}
	return (0);
}