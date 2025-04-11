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
	unsigned long long vector = merge.vector_sort();
	unsigned long long deque = merge.deque_sort();
	std::cout << "Before : ";
	merge.print_unsort(av);
	std::cout << std::endl << "After : ";
	merge.print_sort_deque();
	std::cout << std::endl << "Time to process a range of elements with <vector>: " << vector << " us" << std::endl;
	std::cout << "Time to process a range of elements with <deque>: " << deque << " us" << std::endl;
}