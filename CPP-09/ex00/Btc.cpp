#include "Btc.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Btc::Btc() : _infile("default") {}

Btc::Btc(std::string& infile) : _infile(infile) {}

Btc::Btc(const Btc& other) : _data(other._data), _infile(other._infile) {}

Btc::~Btc() {}

Btc& Btc::operator=(const Btc& other) {
	if (this != &other) {
		_infile = other._infile;
		_data = other._data;
	}
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

std::string isValidDate(std::string line) {
	std::string date = line.substr(0, 10);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw Btc::errorTime();
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		throw Btc::errorTime();
	if (dash1 != '-' || dash2 != '-')
		throw Btc::errorTime();
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		throw Btc::errorTime();
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day <= daysInMonth[month - 1])
		return date;
	throw Btc::errorTime();
}


float convertfloat(std::string line, bool data) {
	char* end;
	double result;
	if (data)
		result = std::strtod(line.c_str() + line.find(',') + 1, &end);
	else
		result = std::strtod(line.c_str() + line.find('|') + 2, &end);
	if (end[0] || std::isinf(result) || std::isnan(result))
		throw Btc::errorTime();
	if ((result > std::numeric_limits<float>::max() || result < 0) && data) {
		throw Btc::errorConv();
	}
	if (!data && result > 1000)
		throw Btc::errorLarge();
	if (!data && result < 0)
		throw Btc::errorNegative();
	//std::cout << result << std::endl;
	return static_cast<float>(result);
}

bool Btc::creatData() {
	std::string line;
	std::ifstream inputFile("data.csv");
	if (!inputFile) {
		std::cout << "Error data.csv can't be open" << std::endl;
		return false;
	}
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		if (line.length() >= 12 && std::count(line.begin(), line.end(), ',') == 1 && line.find(',') == 10) {
			try {
				_data.insert(std::pair<std::string, float>(isValidDate(line), convertfloat(line, 1)));
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\"" << line << "\"" << std::endl;
			}
		}
		else
			std::cout << "Error bad input => " << "\"" << line << "\"" << std::endl;
	}
	inputFile.close();
	std::cout << "data.csv is now close" << std::endl;
	if (_data.size())
		return true;
	return (false);
}
void Btc::Output(std::string line) {
	float f;
	std::string date = line.substr(0,10);
	isValidDate(date);
	f = convertfloat(line, 0);
	_data.begin();
	std::map<std::string, float>::iterator it = _data.begin();
	if (it->first > date)
		throw Btc::errorBefore();
	while (it != _data.end()) {
		if (it->first >= date)
			break;
		it++;
	}
	if (it == _data.end() || it->first != date)
		it--;
	std::cout << date << " => " << f << " = " << it->second * f << std::endl;
}

void Btc::creatOutput() {
	std::cout << std::endl << "output :" << std::endl;
	std::string line;
	std::ifstream inputFile(_infile.c_str());
	if (!inputFile) {
		std::cout << "Error \"" << _infile << "\" can't be open" << std::endl;
		return;
	}
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		if (line.length() >= 14 && std::count(line.begin(), line.end(), '|') == 1 && line.find('|') == 11) {
			try {
				this->Output(line);
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\"" << line << "\"" << std::endl;
			}
		}
		else
			std::cout << "Error bad input => " << "\"" << line << "\"" << std::endl;
	}
	inputFile.close();
}

const char* Btc::errorConv::what() const throw() {
	return ("Error convertion => ");
}

const char* Btc::errorLarge::what() const throw() {
	return ("Error too large a number => ");
}

const char* Btc::errorBefore::what() const throw() {
	return ("Error There is now date before => ");
}

const char* Btc::errorTime::what() const throw() {
	return ("Error bad input => ");
}

const char* Btc::errorNegative::what() const throw() {
	return ("Error not a positive number => ");
}
