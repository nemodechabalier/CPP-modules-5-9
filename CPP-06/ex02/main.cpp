#include "Base.hpp"

int main() {
	{
		Base* a = new A;
		Base* b = new B;
		Base* c = new C;
		identify(a);
		identify(b);
		identify(c);
		delete a;
		delete b;
		delete c;
	}
	{
		A a;
		B b;
		C c;
		identify(a);
		identify(b);
		identify(c);
	}
	{
		//for (int i = 0; i < 100; i++) {
		//	Base *ptr = generate();
		//	identify(ptr);
		//	delete ptr;
		//}
	}

}