#include <Bureaucrat.hpp>
#include <Form.hpp>

int main (void)
{
	try {
		std::cout << "\n|----------------------------|" << std::endl;
		std::cout << "|    Test for Form signed    |" << std::endl;
		std::cout << "|----------------------------|\n" << std::endl;
		Bureaucrat Susana("Susana", 150);
		Form formPegasus("formPegasus", 150, 150);
		Susana.signForm(formPegasus);
		std::cout << formPegasus << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n|----------------------------------|" << std::endl;
		std::cout << "|    Test for not enought grade    |" << std::endl;
		std::cout << "|----------------------------------|\n" << std::endl;
		Bureaucrat Paco("Paco", 149);
		Form badform("badform", 1, 150);//tengo que hacer que ese '1' sea el valor de firma minimo y a la hora de firmar se compara con ese y el nivel del burócrata
		Paco.signForm(badform);
		std::cout << badform << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
