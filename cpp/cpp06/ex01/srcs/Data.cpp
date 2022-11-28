#include "../includes/Data.hpp"



uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	uintptr_t raw = serialize(&data);

	std::cout << data.s1 << std::endl;
	std::cout << data.n << std::endl;
	std::cout << data.s2 << std::endl;

	Data* ptr = deserialize(raw);

	std::cout << ptr->s1 << std::endl;
	std::cout << ptr->n << std::endl;
	std::cout << ptr->s2 << std::endl;
}
