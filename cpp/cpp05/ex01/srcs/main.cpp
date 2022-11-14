#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat		bob1("Bob", 1);
	Bureaucrat		bob2("Bob", 2);
	Form			form1("Form1", 1, 1);
	try
	{
		Bureaucrat	bob("Bob", 1);
		std::cout << bob;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		form("Formulaire", 0, 0);
		std::cout << form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		form("Formulaire", 151, 151);
		std::cout << form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "ALLO" << form1;
		form1.beSigned(bob1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bob1.signForm(form1);
		std::cout << form1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << form1;
		form1.beSigned(bob2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << form1;
		bob2.signForm(form1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
