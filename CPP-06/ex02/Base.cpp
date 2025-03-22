#include "Base.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Base::~Base() {
	//std::cout << "Base: default destructor called" << std::endl;
}


/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

Base* generate() {
	int r = rand() % 3;  // Génère un nombre entre 0 et 2

	switch (r) {
	case 0:
		return new A;
	case 1:
		return new B;
	default:
		return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "It's type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's type C" << std::endl;
}

//void identify(Base& p) {
//	try {
//		(void)dynamic_cast<A&>(p);
//		std::cout << "It's type A" << std::endl;
//	}
//	catch (std::exception &) {}

//	try {
//		(void)dynamic_cast<B&>(p);
//		std::cout << "It's type B" << std::endl;
//	}
//	catch (std::exception &) {}

//	try {
//		(void)dynamic_cast<C&>(p);
//		std::cout << "It's type C" << std::endl;
//	}
//	catch (std::exception &) {}
//}
void identify(Base& p) {
    if (typeid(p) == typeid(A))
        std::cout << "It's type A" << std::endl;
    else if (typeid(p) == typeid(B))
        std::cout << "It's type B" << std::endl;
    else if (typeid(p) == typeid(C))
        std::cout << "It's type C" << std::endl;
}