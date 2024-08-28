#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class  Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        int const           _signGrade;
    	int const           _execGrade;
    public:
		Form(void);
		Form(std::string const name, int const signGrade, int const execGrade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);
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
		int	getSignGrade() const;
		int	getExecGrade() const;
		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);

#endif