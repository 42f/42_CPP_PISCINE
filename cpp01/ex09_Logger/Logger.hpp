#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <string>

class Logger
{

	public:

		int				log(std::string const &dest, std::string const & message);
		static const	std::string	toConsole;
		static const	std::string	toFile;


		Logger( std::string const destFile );
		~Logger();

	private:

		std::string					_makeLogEntry(std::string rawEntry);
		int							_logToConsole(std::string entry);
		int							_logToFile(std::string entry);
		std::string					_destFile;
};

#endif /* ********************************************************** LOGGER_H */
