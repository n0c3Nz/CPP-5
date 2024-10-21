#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

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

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) {
    if (this != &copy) {
        for (int i = 0; i < 3; i++) {
            _formNames[i] = copy._formNames[i];
            _formCreators[i] = copy._formCreators[i];
        }
    }
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    for (int i = 0; i < 3; i++) {
        if (formName == _formNames[i]) {
            AForm* form = (this->*_formCreators[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    throw std::runtime_error("Form name not found.");
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}