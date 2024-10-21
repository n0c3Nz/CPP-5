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
        AForm* (Intern::*_formCreators[3])(const std::string&);

    public:
        Intern(void);
        Intern(const Intern &copy);
        ~Intern();

        Intern &operator=(const Intern &copy);

        AForm *makeForm(const std::string &formName, const std::string &target);

    private:
        AForm *createPresidentialPardonForm(const std::string &target);
        AForm *createRobotomyRequestForm(const std::string &target);
        AForm *createShrubberyCreationForm(const std::string &target);
};

#endif