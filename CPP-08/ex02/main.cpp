#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "test list ::" << std::endl << std::endl;
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << mlist.back() << std::endl; // Équivalent de top() pour une liste
		mlist.pop_back();

		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}
	{
		std::cout << std::endl << "MutantStack list ::" << std::endl << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << "Test canonique form" << std::endl << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> copy(mstack);
		MutantStack<int> Operator;
		Operator = copy;
		std::cout << "default stack : " << mstack << std::endl;
		std::cout << "copy constructor : " << copy << std::endl;
		std::cout << "operator = " << Operator << std::endl;
	}
	return 0;

}