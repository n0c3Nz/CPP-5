#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
int main (void)
{
	Bureaucrat bureaucrat("Moriarty", 4);
	ShrubberyCreationForm form("Home");// min: 145, 137
	try {
		std::cout << "\n -- SIGN & EXEC SHRUBBERY CREATION FORM --\n" << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	RobotomyRequestForm robotomy("Robotomy");// min: 72, 45
	try {
		std::cout << "\n -- SIGN & EXEC ROBOTOMY REQUEST FORM --\n" << std::endl;
		bureaucrat.signForm(robotomy);
		bureaucrat.executeForm(robotomy);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	PresidentialPardonForm pardon("Pardon");// min: 25, 5
	try {
		std::cout << "\n -- SIGN & EXEC PRESIDENTIAL PARDON FORM --\n" << std::endl;
		bureaucrat.signForm(pardon);
		bureaucrat.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n -- --\n" << std::endl;

	return 0;
}
