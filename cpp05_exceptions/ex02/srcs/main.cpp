# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) 	{

	Bureaucrat					bob("bob", 1);
	std::cout << RED_COLOR << std::endl << "[Test: ShrubberyCreationForm]" << RESET_COLOR << std::endl;
	{
		ShrubberyCreationForm		f1("home");

		bob.executeForm(f1);
		bob.signForm(f1);
		bob.executeForm(f1);
		std::cout << RED_COLOR << "[ --> Cat output file]" << RESET_COLOR << std::endl;
		system("cat ./home_shrubbery");
	}
	std::cout << RED_COLOR << std::endl << "[Test: RobotomyRequestForm]" << RESET_COLOR << std::endl;
	{
		RobotomyRequestForm		f1("Human");

		bob.executeForm(f1);
		bob.signForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
	}

	std::cout << RED_COLOR << std::endl << "[Test: PresidentialPardonForm]" << RESET_COLOR << std::endl;
	{
		PresidentialPardonForm		f1("Trump");

		bob.executeForm(f1);
		bob.signForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f1);
	}

	return 0;
}
