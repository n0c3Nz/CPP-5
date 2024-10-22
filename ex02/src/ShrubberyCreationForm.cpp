#include <ShrubberyCreationForm.hpp>


ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	//std::cout << "Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	//std::cout << _name << "Parameter constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	//std::cout << "Copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "Destructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	//std::cout << "Assignation operator called." << std::endl;
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename);
	try {
		if (!file.is_open())
			throw std::runtime_error("Error: could not open file.");
		file << TREE;
	}catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	file.close();
}
