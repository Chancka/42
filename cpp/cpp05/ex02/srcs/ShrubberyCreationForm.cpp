#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &rhs)
		Form::operator=(rhs);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::ofstream ofs;
	std::string	filename;

	filename = _target + "_shrubbery";
	ofs.open(filename.c_str());
	ofs << "         v" << std::endl;
	ofs << "        >X<" << std::endl;
	ofs << "         A" << std::endl;
	ofs << "        d$b" << std::endl;
	ofs << "      .d\\$$b." << std::endl;
	ofs << "    .d$i$$\\$$b." << std::endl;
	ofs << "  .d$$@ii@$$\\$$b." << std::endl;
	ofs << "  d$@i@@@i@$$\\$$b" << std::endl;
	ofs << " d$@@@i@@@$$\\$$@b" << std::endl;
	ofs << "d$@$$$i$$@$$\\$$i@b" << std::endl;
	ofs << "4ii$$$$$i$$$\\$$@@ib" << std::endl;
	ofs << "$$$$$$$$$$$$$$$$$$$" << std::endl;
	ofs << "$$$$$$$$$$$$$$$$$$$" << std::endl;
	ofs << "$$$$$$$$$$$$$$$$$$$" << std::endl;
	ofs << " $$$i$$$$$$$$$$@$$" << std::endl;
	ofs << "  $$$$$$$$$$$$$$$" << std::endl;
	ofs << "   $$$\\$$$$$$$@$$" << std::endl;
	ofs << "    $$$$$$$$$$$$" << std::endl;
	ofs << "     $$$$$$$$$$" << std::endl;
	ofs << "      $$$$$$$$" << std::endl;
	ofs << "       $$$$$$" << std::endl;
	ofs << "        $$$" << std::endl;
	ofs << "         $" << std::endl;
	ofs.close();
}
