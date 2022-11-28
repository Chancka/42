#include "../includes/iter.hpp"

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int		array[] = {1, 2, 3, 4, 5};
	std::string	str[] = {"Hello", "World", "!"};

	iter(array, 5, print);
	iter(str, 3, print);
	return (0);
}
