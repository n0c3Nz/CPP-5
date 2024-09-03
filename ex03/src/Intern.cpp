#include <Intern.hpp>

Intern::Intern(void)
{
    _formNames[0] = "Presidential pardon";
    _formNames[1] = "Robotomy request";
    _formNames[2] = "Shrubbery creation";
    _formCreators[0] = &Intern::createPresidentialPardonForm;
    _formCreators[1] = &Intern::createRobotomyRequestForm;
    _formCreators[2] = &Intern::createShrubberyCreationForm;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == _formNames[i])
            return (this->*_formCreators[i])(target);
    }
    throw std::runtime_error("Form name not found.");
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}