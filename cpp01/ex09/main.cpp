#include "Logger.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )
{
	Logger		log("file.log");
	std::string	entry;

	log.log(Logger::toFile, "Log creation");
	log.log(Logger::toFile, "Main function starts");
	for (int i = 0; i < 2; i++)
	{
		std::cout << RED_COLOR << "[Enter text to log to screen...]" << RESET_COLOR << std::endl;
		std::getline(std::cin, entry);
		if (log.log(Logger::toConsole, entry) != 0)
			std::cout << "Logger function encoutered and error." << std::endl;
	}
	for (int i = 0; i < 2; i++)
	{
		std::cout << RED_COLOR << "[Enter text to log to log file...]" << RESET_COLOR << std::endl;
		std::getline(std::cin, entry);
		if (log.log(Logger::toFile, entry) != 0)
			std::cout << "Logger function encoutered and error." << std::endl;
	}
	log.log(Logger::toFile, "Main function ends");
}
