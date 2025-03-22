#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
	std::vector<int> v;
	std::cout << "Vector :" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		v.push_back(i);
	}
	try {
		for (size_t i = 0; i < 6; i++) {
			std::cout << easyfind(v,i) << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::deque<int> d;
	std::cout << std::endl << "Deque :" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		d.push_back(i);
	}
	try {
		for (size_t i = 0; i < 6; i++) {
			std::cout << easyfind(d,i) << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::list<int> l;
	std::cout << std::endl << "list :" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		l.push_back(i);
	}
	try {
		for (size_t i = 0; i < 6; i++) {
			std::cout << easyfind(l,i) << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}