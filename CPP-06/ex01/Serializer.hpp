#pragma once

#include <string>
#include <iostream>
#include "Data.hpp"
#include <stdint.h>


class Serializer
{
private:
	Serializer();
public:
	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


