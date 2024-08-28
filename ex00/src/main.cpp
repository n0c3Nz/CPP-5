#include <Bureaucrat.hpp>

int main (void)
{
	try {
		std::cout << "\n|--------------------------|" << std::endl;
		std::cout << "|Test for ('Paco') & ('-1')|" << std::endl;
		std::cout << "|--------------------------|\n" << std::endl;
		Bureaucrat test("Paco", -1);
		std::cout << test << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n|----------------------------|" << std::endl;
		std::cout << "|Test for Decrease & Increase|" << std::endl;
		std::cout << "|----------------------------|\n" << std::endl;
		Bureaucrat test("Susana", 150);
		std::cout << test << std::endl;
		test.IncreaseGrade();
		std::cout << test << std::endl;
		test.DecreaseGrade();
		std::cout << test << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n|----------------------------|" << std::endl;
	std::cout << "|        Test for <<         |" << std::endl;
	std::cout << "|----------------------------|\n" << std::endl;
	Bureaucrat test2("Susana", 42);
	std::cout << test2 << std::endl;

	return 0;
}
