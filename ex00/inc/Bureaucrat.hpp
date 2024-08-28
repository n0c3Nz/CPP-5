#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
	public:
		Bureaucrat(void);//OCCF
		Bureaucrat(std::string name, int grade);//OCCF
		Bureaucrat(const Bureaucrat &copy);//OCCF
		Bureaucrat &operator=(const Bureaucrat &copy);//OCCF
		~Bureaucrat();
		void IncreaseGrade(void);
		void DecreaseGrade();
		std::string getName() const;
		int getGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &ref);

#endif