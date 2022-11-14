#include "../includes/Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor of Form called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor called for Form" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Assignation constructor called for Form" << std::endl;
	this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor of Form called" << std::endl;
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << rhs.getName() << " is signed: " << rhs.getIsSigned() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (o);
}

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "Default constructor called for GradeTooHighException" << std::endl;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &other)
{
	std::cout << "Copy constructor called for GradeTooHighException" << std::endl;
	*this = other;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException &other)
{
	(void)other;
	std::cout << "Assignation constructor called for GradeTooHighException" << std::endl;
	return (*this);
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "Destructor of GradeTooHighException called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "Default constructor called for GradeTooLowException" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &other)
{
	std::cout << "Copy constructor called for GradeTooLowException" << std::endl;
	*this = other;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &other)
{
	(void)other;
	std::cout << "Assignation constructor called for GradeTooLowException" << std::endl;
	return (*this);
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "Destructor of GradeTooLowException called" << std::endl;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
