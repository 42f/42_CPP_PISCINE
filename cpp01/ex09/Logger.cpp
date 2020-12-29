#include <sstream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <time.h>
#include <ctime>
#include "Logger.hpp"

const std::string	Logger::toConsole = "toConsole";
const std::string	Logger::toFile = "toFile";
std::string			Logger::_destFile;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Logger::Logger( std::string const destFile )
{
 	_destFile = destFile;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Logger::~Logger()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

int				Logger::_logToConsole(std::string logEntry)	{
	std::clog << logEntry.c_str() << std::endl;
	return (0);
}

int				Logger::_logToFile(std::string logEntry)	{
	std::ofstream	ofs(Logger::_destFile.c_str(), std::ofstream::app);

	if (ofs.good() == true)
	{
		ofs << logEntry << std::endl;
		ofs.close();
		return (0);
	}
	else
		return (1);
}

std::string		Logger::_makeLogEntry(std::string rawEntry)	{
	std::stringstream	logEntry;
	std::stringstream	timestamp;
	time_t				theTime = time(NULL);
	struct tm			*aTime = localtime(&theTime);

 	timestamp << aTime->tm_year + 1900;
	timestamp << std::setw(2) << std::setfill('0') << aTime->tm_mon + 1;
	timestamp << std::setw(2) << std::setfill('0') << aTime->tm_mday;
	timestamp << '_';
	timestamp << std::setw(2) << std::setfill('0') << aTime->tm_hour << '.';
	timestamp << std::setw(2) << std::setfill('0') << aTime->tm_min << '.';
	timestamp << std::setw(2) << std::setfill('0') << aTime->tm_sec;
	logEntry << "--" << getpid() << "-- " << "[" << timestamp.str() << "] - " << rawEntry;
	return (logEntry.str());
}

int				Logger::log(std::string const &dest, std::string const & message)	{
	std::string		dest_list[2] = { Logger::toConsole, Logger::toFile };
	int				(Logger::*function_list[2])(std::string) = { &Logger::_logToConsole, &Logger::_logToFile };
	int				i = 0;

	while(dest_list[i] != dest && i < 2)
		i++;
	return ((this->*function_list[i])(Logger::_makeLogEntry(message)));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
