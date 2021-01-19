# include "Bureaucrat.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	{
		std::cout << RED_COLOR << "[instanciate OK]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 100);
			std::cout << "getName = " << bob.getName() << std::endl;
			std::cout << "getGrad = " << bob.getGrade() << std::endl;
			std::cout << bob;
		}
		catch (std::exception & e)	{
			std::cout << "Got an Exception !! " << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[instanciate grade 200]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 200);
			std::cout << "getName = " << bob.getName() << std::endl;
			std::cout << "getGrad = " << bob.getGrade() << std::endl;
			std::cout << bob;
		}
		catch (std::exception & e)	{
			std::cout << "Got an Exception !! " << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[instanciate grade -10]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", -10);
			std::cout << "getName = " << bob.getName() << std::endl;
			std::cout << "getGrad = " << bob.getGrade() << std::endl;
			std::cout << bob;
		}
		catch (std::exception & e)	{
			std::cout << "Got an Exception !! " << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[instanciate grade 0]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 0);
			std::cout << "getName = " << bob.getName() << std::endl;
			std::cout << "getGrad = " << bob.getGrade() << std::endl;
			std::cout << bob;
		}
		catch (std::exception & e)	{
			std::cout << "Got an Exception !! " << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[Increment / Decrement functions OK]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 100);
			std::cout << "At start :" << bob;
			std::cout << "[increment call]" << std::endl;
			bob.incrementGrade();
			std::cout << bob;
			std::cout << "[decrement call]" << std::endl;
			bob.decrementGrade();
			std::cout << bob;
		}
		catch (std::exception & e)	{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[Increment / Decrement functions NOT OK]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 150);
			std::cout << "At start :" << bob;
			std::cout << "[increment call]" << std::endl;
			bob.incrementGrade();
			std::cout << bob;
			std::cout << "[decrement call]" << std::endl;
			bob.decrementGrade();
			std::cout << bob;
			std::cout << "[decrement call]" << std::endl;
			bob.decrementGrade();
			std::cout << bob;
			std::cout << "THIS WILL NOT PRINT" << std::endl;
		}
		catch (std::exception & e)	{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << RED_COLOR << "[Increment / Decrement functions NOT OK]" << RESET_COLOR << std::endl;
		try {
			Bureaucrat	bob("bob", 1);
			std::cout << "At start :" << bob;
			std::cout << "[decrement call]" << std::endl;
			bob.decrementGrade();
			std::cout << bob;
			std::cout << "[increment call]" << std::endl;
			bob.incrementGrade();
			std::cout << bob;
			std::cout << "[increment call]" << std::endl;
			bob.incrementGrade();
			std::cout << bob;
			std::cout << "THIS WILL NOT PRINT" << std::endl;
		}
		catch (std::exception & e)	{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
