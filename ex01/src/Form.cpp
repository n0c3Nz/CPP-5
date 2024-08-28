#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Default constructor called." << std::endl;
}

Form	&Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (Form::GradeTooLowException());
	if (this->_execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (Form::GradeTooLowException());
	std::cout << name << ": " << "Parameter constructor called." << std::endl;
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade){
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << ":" << " successfully signed " << this->_name << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &stream, Form const &form)
{
	stream << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << form.getIsSigned();
	return (stream);
}

Form::~Form(void) {
	std::cout << _name << ":" << " Called Default Destructor" << std::endl;
}