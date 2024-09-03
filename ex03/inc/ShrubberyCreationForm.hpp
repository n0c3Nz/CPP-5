#ifndef SHRUBBERYCREATIONFORM_HPP 
# define SHRUBBERYCREATIONFORM_HPP

#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <fstream>


#define TREE "       ccee88oo\n" \
              "  C8O8O8Q8PoOb o8oo\n" \
              " dOB69QO8PdUOpugoO9bD\n" \
              "CgggbU8OU qOp qOdoUOdcb\n" \
              "    6OuU  /p u gcoUodpP\n" \
              "       \\\\//  /douUP\n" \
              "         \\\\////\n" \
              "          |||/\\\n" \
              "          |||\\/\n" \
              "          |||||\n" \
              "    .....//||||\\....\n"




class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		void execute(Bureaucrat const &executor) const;
};

#endif