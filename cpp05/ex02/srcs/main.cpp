# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) 	{

	Bureaucrat					bob("bob", 1);

	PresidentialPardonForm		f1("home");

	bob.executeForm(f1);
	bob.signForm(f1);
	std::cout << "signed ? " << f1.getSignStatus() << std::endl;
	bob.executeForm(f1);

	return 0;
}
