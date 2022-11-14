#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

	Form* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *ppf << std::endl;

	Form* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *scf << std::endl;

	return (0);
}
