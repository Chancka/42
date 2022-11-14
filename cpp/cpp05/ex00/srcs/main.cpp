#include "../includes/Bureaucrat.hpp"

int main(void)
{
	std::cout << "Creating a Bureaucrat with a grade of 0" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 0);
		std::cout << bob;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bob("Bob", 151);
		std::cout << bob;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bob("Bob", 1);
		std::cout << bob;
		bob.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bob("Bob", 150);
		std::cout << bob;
		bob.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bob("Bob", 1);
		std::cout << bob;
		bob.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
