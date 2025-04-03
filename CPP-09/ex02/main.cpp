#include "PmergeMe.hpp"

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Error" << std::endl; 
		return 0;
	}
	PmergeMe merge;
	if (!merge.takenb(av + 1)) {
		std::cerr << "Error" << std::endl;
		return 0;
	}
	std::cerr << "is ok" << std::endl;
}