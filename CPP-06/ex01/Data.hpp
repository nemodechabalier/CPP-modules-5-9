#pragma once

#include <string>
#include <iostream>

class Data
{
public:
	Data();
	Data(const Data& other);
	~Data();
	Data& operator=(const Data& other);
	std::string _name;
	int _age;
};

