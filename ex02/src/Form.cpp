#include <Form.hpp>
#include <Bureaucrat.hpp>

AForm::AForm(void) : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Default constructor called." << std::endl;
}

AForm	&AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (AForm::GradeTooLowException());
	if (this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
	std::cout << name << ": " << "Parameter constructor called." << std::endl;
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed.");
    if (executor.getGrade() > this->getExecGrade())
        throw std::runtime_error("Bureaucrat grade too low to execute form.");
    std::cout << "Executing form: " << this->getName() << std::endl;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade){
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << ":" << " successfully signed " << this->_name << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &stream, AForm const &form)
{
	stream << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << form.getIsSigned();
	return (stream);
}

AForm::~AForm(void) {
	std::cout << _name << ":" << " Called Default Destructor" << std::endl;
}