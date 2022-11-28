#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat		*bur1 = new Bureaucrat("bur1", 1);
	Bureaucrat		*bur2 = new Bureaucrat("bur2", 50);
	Bureaucrat		*bur3 = new Bureaucrat("bur3", 150);

	Form			*form1 = new ShrubberyCreationForm("home");
	Form			*form2 = new RobotomyRequestForm("room");
	Form			*form3 = new PresidentialPardonForm("garden");

	std::cout << *bur1 << std::endl;
	std::cout << *bur2 << std::endl;
	std::cout << *bur3 << std::endl;


	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;

	bur1->signForm(*form1);
	bur1->signForm(*form2);
	bur1->signForm(*form3);

	std::cout << std::endl;

	bur2->signForm(*form1);
	bur2->signForm(*form2);
	bur2->signForm(*form3);

	std::cout << std::endl;

	bur3->signForm(*form1);
	bur3->signForm(*form2);
	bur3->signForm(*form3);

	std::cout << std::endl;

	bur1->executeForm(*form1);
	bur1->executeForm(*form2);
	bur1->executeForm(*form3);

	std::cout << std::endl;

	bur2->executeForm(*form1);
	bur2->executeForm(*form2);
	bur2->executeForm(*form3);

	std::cout << std::endl;

	bur3->executeForm(*form1);
	bur3->executeForm(*form2);
	bur3->executeForm(*form3);

	delete bur1;
	delete bur2;
	delete bur3;

	delete form1;
	delete form2;
	delete form3;

	return (0);
}
