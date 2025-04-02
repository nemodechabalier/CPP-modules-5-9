#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <climits>
#include <sstream>
#include <cmath>
#include <exception>


class Btc
{
private:

	std::map<std::string, float> _data;
	std::string _infile;

public:
	Btc();
	Btc(std::string& infile);
	Btc(const Btc& other);
	~Btc();
	Btc& operator=(const Btc& other);

	bool creatData();
	void creatOutput();
	void Output(std::string line);

	class errorConv : public std::exception {
		const char *what() const throw();
	};

	class errorTime : public std::exception {
		const char *what() const throw();
	};

	class errorBefore : public std::exception {
		const char *what() const throw();
	};

	class errorNegative : public std::exception {
		const char *what() const throw();
	};

	class errorLarge : public std::exception {
		const char *what() const throw();
	};
};