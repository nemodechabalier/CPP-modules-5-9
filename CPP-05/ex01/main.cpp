#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat b("Thomas", 150);
	try {
		std::cout << b << std::endl;
		Form f("inscription to 42", 20, 30);
		//Form f2("inscription to 42", 200, 30);
		//b.decrementGrade(1);
		//f.beSigned(b);
		b.incrementGrade(149);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		f.beSigned(b);
		//b.incrementGrade(1);
		//b.incrementGrade(2147483648);
		//Bureaucrat c("test", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}