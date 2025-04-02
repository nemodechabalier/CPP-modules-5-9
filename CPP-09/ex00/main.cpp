#include "Btc.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error need 1 arg" << std::endl;
		return 0;
	}
	std::string infile = av[1];
	if(infile.length() > 0) {
		std::cout << "open data.csv" << std::endl;
		Btc btc(infile);
		if (btc.creatData()) {
			btc.creatOutput();
		}
	}
	return 0;
}