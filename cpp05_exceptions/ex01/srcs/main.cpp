# include "Form.hpp"
# include "Bureaucrat.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

void	testFormInitalization(std::string const &test, std::string const &name, int signGrade, int execGrade)	{

	std::cout << RED_COLOR << test << RESET_COLOR << std::endl;
	try {
		Form	f1(name, signGrade, execGrade);
		std::cout << "Form name : " << f1.getName() << std::endl;
		std::cout << "Form signature status : " << f1.getSignStatus() << std::endl;
		std::cout << "Form signature grade  : " << f1.getSignGrade() << std::endl;
		std::cout << "Form execution grade  : " << f1.getExecGrade() << std::endl;
	}
	catch (std::exception & e)	{
		std::cout << "GOT EXCEPTION !!!" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

void	testFormSignature(std::string const &test, int grade)	{


	std::cout << RED_COLOR << test << RESET_COLOR << std::endl;
	Form f1("Form __42__", 100, 100);
	Bureaucrat	bob("bob", grade);
	std::cout << "Status form before : " << f1.getSignStatus() << std::endl;
	bob.signForm(f1);
	std::cout << "Status form after  : " << f1.getSignStatus() << std::endl;
}

int		main( void ) 	{

	testFormInitalization("[Form instantiationi OK]", "Form 456412d - 8", 120, 100);
	testFormInitalization("[Form instantiationi NOT OK: too low]", "Form D42578 - 8", 200, 100);
	testFormInitalization("[Form instantiationi NOT OK: too low]", "Form D42578 - 8", 120, 200);
	testFormInitalization("[Form instantiationi NOT OK: too high]", "Form D42578 - 8", 0, 100);
	testFormInitalization("[Form instantiationi NOT OK: too high]", "Form D42578 - 8", 120, 0);

	testFormSignature("[Signature OK]", 1);
	testFormSignature("[Signature NO OK: too low]", 120);
	return 0;
}
