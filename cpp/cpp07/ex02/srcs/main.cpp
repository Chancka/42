#include "../includes/Array.hpp"

int	main()
{
	Array<int>	*array = new Array<int>(5);
	Array<int>	*array2 = new Array<int>(*array);
	Array<int>	*array3 = new Array<int>(10);
	Array<char>	*array4 = new Array<char>(10);

	for (unsigned int i = 0; i < array->size(); i++)
		(*array)[i] = i;

	// print array
	for (unsigned int i = 0; i < array->size(); i++)
		std::cout << (*array)[i] << std::endl;

	try // try to access an element out of range
	{
		std::cout << (*array)[array->size()] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	*array3 = *array; // assignation operator
	// print array3
	for (unsigned int i = 0; i < array3->size(); i++)
		std::cout << (*array3)[i] << std::endl;

	// fill array4 with chars
	for (unsigned int i = 0; i < array4->size(); i++)
		(*array4)[i] = 'a' + i;
	
	// print array4
	for (unsigned int i = 0; i < array4->size(); i++)
		std::cout << (*array4)[i] << std::endl;

	std::cout << "array size: " << array->size() << std::endl;
	std::cout << "array2 size: " << array2->size() << std::endl;
	std::cout << "array3 size: " << array3->size() << std::endl;
	std::cout << "array4 size: " << array4->size() << std::endl;

	delete array;
	delete array2;
	delete array3;
	delete array4;
	return (0);
}
