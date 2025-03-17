#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("test", 150);
	try {
		std::cout << b << std::endl;
		//b.decrementGrade(1);
		b.incrementGrade(149);
		std::cout << b << std::endl;
		//b.incrementGrade(1);
		//b.incrementGrade(2147483648);
		//Bureaucrat c("test", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}