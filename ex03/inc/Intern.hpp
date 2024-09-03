#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <Form.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

class Intern
{
private:
    std::string _formNames[3];
    AForm *(Intern::*_formCreators[3])(std::string);

public:
    Intern(void);
    Intern(const Intern &copy);
    ~Intern();

    Intern &operator=(const Intern &copy);

    AForm *makeForm(std::string formName, std::string target);

private:
    AForm *createPresidentialPardonForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createShrubberyCreationForm(std::string target);
};

#endif