#include "Serializer.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Serializer::Serializer() {
	std::cout << "Serializer: default constructor called" << std::endl;
}


/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr); 
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}