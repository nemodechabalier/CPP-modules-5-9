#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cctype>

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

	bool takenb(char **av);

};