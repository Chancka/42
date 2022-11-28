#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat		bob1("Bob1", 1);
	Bureaucrat		bob2("Bob2", 2);
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
	std::cout << form1;
	bob1.signForm(form1); // bob1 grade is 1, form1 grade is 1
	std::cout << form1;
	bob2.signForm(form1); // bob2 grade is too low
	return (0);
}
