#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main() {
    try {
        Intern intern;
        Bureaucrat bureaucrat("Moriarty", 1);

        AForm *form = intern.makeForm("Shrubbery creation", "Home");
        if (form) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form; // Liberar la memoria asignada
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
