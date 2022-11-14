#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const & src);
		~Form(void);

		Form &	operator=(Form const & rhs);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(Bureaucrat const & bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:

		Form(void);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & src);
				~GradeTooHighException(void) throw();

				GradeTooHighException &	operator=(GradeTooHighException const & rhs);

				virtual const char *	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & src);
				~GradeTooLowException(void) throw();

				GradeTooLowException &	operator=(GradeTooLowException const & rhs);

				virtual const char *	what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				FormNotSignedException(void);
				FormNotSignedException(FormNotSignedException const & src);
				~FormNotSignedException(void) throw();

				FormNotSignedException &	operator=(FormNotSignedException const & rhs);

				virtual const char *	what() const throw();
		};

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		const std::string	_target;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif
