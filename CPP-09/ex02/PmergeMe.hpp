#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <ostream>
#include <sys/time.h>

class PmergeMe
{
private:

	std::vector<int> _vector;
	std::deque<int> _deque;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);

	bool takenb(char** av);
	unsigned long long vector_sort();
	unsigned long long deque_sort();

	void print_unsort(char** av);
	void print_sort();
	void print_sort_deque();

	//std::vector<int> sort(std::vector<int>& vector);
};