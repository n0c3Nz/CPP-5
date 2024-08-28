#include <Bureaucrat.hpp>

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << _name << ": " << "Bureaucrat Called Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << _name << ": " << "Called Bureaucrat parameter Constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << _name << ": " << "Bureaucrat Called Copy Constructor" << std::endl;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::DecreaseGrade(){
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
	std::cout << "Grade decreased." << std::endl;
}

void Bureaucrat::IncreaseGrade(){
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
	std::cout << "Grade increased." << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &copy)
{
	stream << copy.getName() << ", bureaucrat grade " << copy.getGrade();
	return (stream);
}

Bureaucrat::~Bureaucrat(){
	std::cout << _name << ": " << "Bureaucrat Called Default Destructor" << std::endl;
}