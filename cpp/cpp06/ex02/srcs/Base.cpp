#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate(void)
{
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "A" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C" << std::endl;
		return new C;
	}
}

void identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "From pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "From pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "From pointer: C" << std::endl;
}

void identify_from_reference(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "From reference: A" << std::endl;
	}
	catch (std::exception& e)
	{
		(void)e;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "From reference: B" << std::endl;
	}
	catch (std::exception& e)
	{
		(void)e;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "From reference: C" << std::endl;
	}
	catch (std::exception& e)
	{
		(void)e;
	}
}

Base::~Base()
{
}

A::~A()
{
}

B::~B()
{
}

C::~C()
{
}
