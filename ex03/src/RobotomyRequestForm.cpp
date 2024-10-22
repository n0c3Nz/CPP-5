#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
	//std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	//std::cout << "RobotomyRequestForm parameter constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	//std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
	//std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	this->_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::srand(std::time(0));
	int randomValue = std::rand() % 11;// esto hace que sea random entre 0 y 10
	try {
		if (!this->getIsSigned())
			throw std::runtime_error("Form is not signed.");
		if (executor.getGrade() > this->getExecGrade())
			throw std::runtime_error("Bureaucrat grade too low to execute form.");
		std::cout << "Executing form: " << this->getName() << std::endl;
		if (randomValue % 2)
			std::cout << "Robotomy request on " << this->_target << " has been successful." << std::endl;
		else
			std::cout << "Robotomy request on " << this->_target << " has failed." << std::endl;
	}catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}