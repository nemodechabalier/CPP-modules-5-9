#include "Span.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Span::Span() : _N(10000) {
	//std::cout << "Span: default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	//std::cout << "Span: custom constructor called" << std::endl;
}

Span::Span(const Span& other) :_N(other._N) {
	_v = other._v;
	//std::cout << "Span: copy constructor called" << std::endl;
}

Span::~Span() {
	//std::cout << "Span: default destructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_v = other._v;
	}
	//std::cout << "Span: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void Span::addNumber(int nb) {
	if (_v.size() >= _N)
		throw overSizeExeption();
	else {
		_v.push_back(nb);
	}
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw ErrornbNExeption();
	else {
		int min = _v[0];
		int max = _v[0];
		for (unsigned int i = 1; i < _v.size(); i++) {
			if (max < _v[i])
				max = _v[i];
			else if (min > _v[i])
				min = _v[i];
		}
		return max - min;
	}
}

inline int abs(int x) {
	return (x > 0) ? x : -x;
}


int Span::shortestSpan() {
	if (_v.size() < 2)
		throw ErrornbNExeption();
	else {
		int shortest = INT_MAX;
		for (unsigned int i = 0; i < _v.size() - 1; i++) {
			if (shortest == 0)
				return shortest;
			for (unsigned int j = i; j < _v.size(); j++) {
				if (j != i && abs(_v[i] - _v[j]) < shortest)
					shortest = abs(_v[i] - _v[j]);
			}
		}
		return shortest;
	}
}

void Span::addNumbers(std::vector<int>::iterator fisrt, std::vector<int>::iterator last) {
	if (std::distance(fisrt, last) + _v.size() > _N)
		throw overSizeExeption();
	else {
		_v.insert(_v.end(), fisrt, last);
	}
}

const char* Span::overSizeExeption::what() const throw() {
	return "Error size to low";
}


const char* Span::ErrornbNExeption::what() const throw() {
	return "Error need more nb";
}
