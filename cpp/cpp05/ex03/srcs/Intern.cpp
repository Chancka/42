#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignation operator called" << std::endl;
	(void)other;
	return *this;
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	Form *form = NULL;
	if (formName == "robotomy request")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new PresidentialPardonForm(target);
	}
	else if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new ShrubberyCreationForm(target);
	}
	else
		std::cout << "Intern cannot create form " << formName << std::endl;
	return form;
}
