#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class  AForm
{
    private:
        const std::string   _name;//Es el nombre del documento
        bool                _isSigned;//Indica si el documento esta firmado
        int           _signGrade;//Es el grado minimo que se necesita para firmar el documento
    	int           _execGrade;//Es el grado minimo que se necesita para ejecutar el documento
    public:
		AForm(void);
		AForm(std::string const name, int const signGrade, int const execGrade);
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
        class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw ()
				{
					return ("Grade too Low.");
				}
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw ()
				{
					return ("Grade too High.");
				}
		};
		class SignTooLowException : public std::exception
		{
			public:
				const char *what() const throw ()
				{
					return ("Grade too High.");
				}
		};

        const std::string	getName() const;
        bool	getIsSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &stream, AForm const &form);

#endif