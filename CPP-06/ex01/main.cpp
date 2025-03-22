#include "Serializer.hpp"

int main() {
	{
		Data* d = new Data;
		uintptr_t test = Serializer::serialize(d);
		Data* d2 = Serializer::deserialize(test);
		if (d == d2)
			std::cout << "same ptr" << std::endl;
		delete d;
	}
	{
		uintptr_t test = Serializer::serialize(NULL);
		Data* d2 = Serializer::deserialize(test);
		if (!d2)
			std::cout << "d2 is NULL" << std::endl;
	}
}