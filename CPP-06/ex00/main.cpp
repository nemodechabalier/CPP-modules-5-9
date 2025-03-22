#include "ScalarConverter.hpp" 

int main(int ac, char **av) {
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else {
		std::cout << "Error wrong nb of args" << std::endl;
		return -1;
	}
	return 1;
}