#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>

int	main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "first " << *it << std::endl;
	++it;
	std::cout << "second " << *it << std::endl;
	--it;
	std::cout << "first " << *it << std::endl;
	std::cout << "----------------" << std::endl;	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "----------------" << std::endl;
	std::list<int> l(mstack.begin(), mstack.end()); // copy constructor
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) // iterator
		std::cout << *it << std::endl;

	// replace MutantStack with std::list
	std::cout << "----------------" << std::endl;
	std::list<int> mstack2;
	mstack2.push_back(5);
	mstack2.push_back(17);
	std::cout << "top " << mstack2.back() << std::endl;
	mstack2.pop_back();
	std::cout << "size " << mstack2.size() << std::endl;
	mstack2.push_back(3);
	mstack2.push_back(5);
	mstack2.push_back(737);
	mstack2.push_back(0);
	std::list<int>::iterator it2 = mstack2.begin();
	std::list<int>::iterator ite2 = mstack2.end();
	std::cout << "first " << *it2 << std::endl;
	++it2;
	std::cout << "second " << *it2 << std::endl;
	--it2;
	std::cout << "first " << *it2 << std::endl;
	std::cout << "----------------" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> l2(mstack2.begin(), mstack2.end()); // copy constructor
	for (std::list<int>::iterator it = l2.begin(); it != l2.end(); ++it) // iterator
		std::cout << *it << std::endl;

	return 0;
}
