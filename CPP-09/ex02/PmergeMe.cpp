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

template <typename Container>
Container generateJacobsthal(int size, Container) {
	Container jacob;
	if (size < 1)
		return jacob;
	int j0 = 0;
	int j1 = 1;
	int jn;
	while (j1 <= size) {
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
		jacob.push_back(j1);
	}
	return jacob;
}

template <typename Container>
void binariInsert(Container& vec, int value) {
	typename Container::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}

template <typename Container>
void insertJacob(Container& result, Container& vector) {
	if (vector.empty())
		return;
	binariInsert(result, vector[0]);
	Container jacobstal = generateJacobsthal(vector.size(),result);
	Container inserted(vector.size(), false);
	inserted[0] = true;
	for (size_t i = 1; i < jacobstal.size(); i++) {
		for (int n = jacobstal[i]; n >= (int)jacobstal[i - 1]; --n) {
			if (n < (int)vector.size() && !inserted[n]) {
				binariInsert(result, vector[n]);
				inserted[n] = true;
			}
		}
	}
}

template <typename Container>
Container sort(Container& vector) {
	Container small, big, result;
	if (vector.size() <= 1)
		return vector;
	for (size_t i = 0; i + 1 < vector.size(); i += 2) {
		if (vector[i] > vector[i + 1])
			std::swap(vector[i], vector[i + 1]);
		small.push_back(vector[i]);
		big.push_back(vector[i + 1]);
	}
	bool rest = vector.size() % 2;
	int n;
	if (rest)
		n = vector.back();
	result = sort(big);
	insertJacob(result, small);
	if (rest)
		binariInsert(result, n);
	return result;
}

unsigned long long PmergeMe::vector_sort() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	_vector = sort(_vector);
	gettimeofday(&end, NULL);
	unsigned long long duration = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	return duration;
}

unsigned long long  PmergeMe::deque_sort() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	_deque = sort(_deque);
	gettimeofday(&end, NULL);
	unsigned long long duration = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	return duration;
}


void PmergeMe::print_sort() {
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i];
		if (i + 1 < _vector.size())
			std::cout << ", ";
	}
}

void PmergeMe::print_sort_deque() {
	for (size_t i = 0; i < _deque.size(); i++) {
		std::cout << _deque[i];
		if (i + 1 < _deque.size())
			std::cout << ", ";
	}
}

void PmergeMe::print_unsort(char** av) {
	for (int i = 1; av[i] != NULL; i++) {
		std::cout << av[i];
		if (av[i + 1] != NULL)
			std::cout << ", ";
	}
}