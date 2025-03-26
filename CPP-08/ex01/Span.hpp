#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <climits>

class Span
{
private:
	std::vector<int> _v;
	unsigned int _N;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	Span& operator=(const Span& other);

	void addNumber(int nb);
	void addNumbers(std::vector<int>::iterator fisrt, std::vector<int>::iterator last);
	int shortestSpan();
	int longestSpan();

	class overSizeExeption : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class ErrornbNExeption : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
