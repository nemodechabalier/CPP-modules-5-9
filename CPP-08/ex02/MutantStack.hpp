#pragma once

#include <string>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack& operator=(const MutantStack& other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

template <typename T>
std::ostream& operator<<(std::ostream& out,  MutantStack<T>& other);

#include "MutantStack.tpp"
