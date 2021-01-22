# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"
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
	Bureaucrat					jim("jim", 148);
	{
		Intern  someRandomIntern;
		AForm*   rrf;

		std::cout << RED_COLOR << std::endl << "[Test: robotomy request]" << RESET_COLOR << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bob.signForm(*rrf);
		bob.executeForm(*rrf);
		bob.executeForm(*rrf);
		bob.executeForm(*rrf);
		bob.executeForm(*rrf);
		jim.executeForm(*rrf);
		std::cout << RED_COLOR << std::endl << "[Test: presidential pardon]" << RESET_COLOR << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Trump");
		bob.signForm(*rrf);
		bob.executeForm(*rrf);
		jim.executeForm(*rrf);
		std::cout << RED_COLOR << std::endl << "[Test: shrubbery creation]" << RESET_COLOR << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		bob.signForm(*rrf);
		bob.executeForm(*rrf);
		std::cout << RED_COLOR << "[ --> Cat output file]" << RESET_COLOR << std::endl;
		system("cat ./home_shrubbery");
		jim.executeForm(*rrf);
	}

	return 0;
}
