#include "Span.hpp"

int main() {
	{
		Span S1;
		Span S2(100000);
		try {
			for (int i = 0; i < 10000; i++) {
				S1.addNumber(i);
			}
			std::cout << "max range is " << S1.longestSpan() << std::endl;
			std::cout << "min range is " << S1.shortestSpan() << std::endl;
			S1.addNumber(10);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "max range is " << S2.longestSpan() << std::endl;
			std::cout << "min range is " << S2.shortestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		S2 = S1;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::vector<int> sp;
		Span s = Span(5);
		sp.push_back(6);
		sp.push_back(3);
		sp.push_back(17);
		sp.push_back(9);
		sp.push_back(11);
		s.addNumbers(sp.begin(), sp.end());
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	return 0;
}
