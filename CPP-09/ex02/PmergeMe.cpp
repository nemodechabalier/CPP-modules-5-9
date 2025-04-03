#include "PmergeMe.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

bool correctInput(char* nb) {
	int start = 0;
	if (nb[0] == '+')
		start = 1;
	if (nb[0] == '+' && !nb[1])
		return false;
	for (int i = start; nb[i] != '\0'; i++) {
		if (!isdigit(nb[i]))
			return false;
	}
	return true;
}

bool PmergeMe::takenb(char** av) {
	for (int i = 0; av[i] != NULL; i++) {
		if (!correctInput(av[i]))
			return false;
		else {
			long l = std::atol(av[i]);
			if (l > INT_MAX || l < 0)
				return false;
			_vector.push_back(static_cast<int>(l));
			_deque.push_back(static_cast<int>(l));
		}
	}
	return true;
}