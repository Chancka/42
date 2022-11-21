#include "../includes/Type.hpp"

int main(int argc, char **argv)
{
	Type    type;

	if (argc == 2)
	{
		type.setAll(argv[1]);
		type.printChar();
		type.printInt();
		type.printFloat();
		type.printDouble();
	}
	else
		std::cout << "Usage: ./convert [value]" << std::endl;
	return 0;
}
