#include "MutantStack.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "MutantStack: default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
	std::cout << "MutantStack: copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack: default destructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	std::cout << "MutantStack: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, MutantStack<T>& other) {
	typename MutantStack<T>::iterator it = other.begin();
	typename MutantStack<T>::iterator end = other.end();
	while (it != end) {
		out << *it;
		it++;
		if (it != end)
			out << " ";
	}
	return out;
}