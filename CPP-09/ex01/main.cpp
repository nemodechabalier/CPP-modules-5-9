#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include <cstdlib>
#include <cctype>

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool applyOperator(std::stack<int, std::list<int> > &nb, char op) {
	if (nb.size() < 2) {
		std::cerr << "Error" << std::endl;
		return false;
	}
	int b = nb.top(); nb.pop();
	int a = nb.top(); nb.pop();
	switch (op)
	{
	case '+': nb.push(a + b); break;
	case '-': nb.push(a - b); break;
	case '*': nb.push(a * b); break;
	case '/':
		if (b == 0) {
			std::cerr << "Error: division by 0" << std::endl;
			return false;
		}
		nb.push(a / b);
		break;
	}
	return true;
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Error: Need 1 argument" << std::endl;
		return 1;
	}
	std::string input = av[1];
	std::stack<int, std::list<int> > nb;
	std::stringstream ss(input);
	std::string token;
	while (ss >> token) {
		if (token.length() == 1 && isOperator(token[0])) {
			if (!applyOperator(nb, token[0]))
				return 0;
		}
		else if (token.length() == 1 && isdigit(token[0]))
			nb.push(token[0] - '0');
		else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	if (nb.size() != 1) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << nb.top() << std::endl;
	return 0;
}