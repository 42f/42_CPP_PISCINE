# include "Converter.hpp"
# include <sstream>
# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <limits>


#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

void	printValues( t_values &val )	{

	if (isprint(val.cVal) == false)
		std::cout << "char: " << "Not displayable" << std::endl;
	else
		std::cout << "char: '" << val.cVal << "'" << std::endl;
	std::cout << "int: " << val.iVal << std::endl;
	std::cout << "float: " << val.fVal << 'f' << std::endl;
	std::cout << "double: "  << val.dVal << std::endl;
}

void	printSpecialValues( t_values &val )	{

	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << val.fVal << 'f' << std::endl;
	std::cout << "double: "  << val.dVal << std::endl;
}

bool  infHandler( std::string &arg )	{

	t_values	val;
	float		sign = 0;

	sign = (arg.at(0) == '+') ? +1 : -1;

	if (arg.find("ff") != std::string::npos)
	{
		val.fVal = sign * std::numeric_limits<float>::infinity();
		val.dVal = static_cast<double>(val.fVal);
	}
	else
	{
		val.dVal = sign * std::numeric_limits<double>::infinity();
		val.fVal = static_cast<float>(val.dVal);
	}
	printSpecialValues(val);
	return (true);
}

bool  nanHandler( __attribute__((unused))std::string  &arg )	{

	t_values	val;

	if (arg.at(arg.length() - 1) == 'f')
	{
		val.fVal = std::numeric_limits<float>::quiet_NaN();
		val.dVal = static_cast<double>(val.fVal);
	}
	else
	{
		val.dVal = std::numeric_limits<double>::quiet_NaN();
		val.fVal = static_cast<float>(val.dVal);
	}
	printSpecialValues(val);
	return (true);
}

bool  floatHandler( std::string  &arg )	{

	char				dump;
	t_values			val;
	std::stringstream	sarg(arg);
	std::cout << "HANDLER : float" << std::endl;
	sarg >> val.fVal;
	if (sarg.fail() == true)
		std::cout << "Error: This result it undefined: the value passed as parameter has overflown!" << std::endl;
	sarg >> dump;
	sarg >> dump;
	if (sarg.eof() == false)
		return (false);
	val.dVal = static_cast<double>(val.fVal);
	val.iVal = static_cast<int>(val.fVal);
	val.cVal = static_cast<char>(val.fVal);
	printValues(val);
	return (true);
}

bool  doubleHandler( std::string  &arg )	{

	char				dump;
	t_values			val;
	std::stringstream	sarg(arg);
	std::cout << "HANDLER : double" << std::endl;
	sarg >> val.dVal;
	if (sarg.fail() == true)
		std::cout << "Error: This result it undefined: the value passed as parameter has overflown!" << std::endl;
	sarg >> dump;
	sarg >> dump;
	if (sarg.eof() == false)
		return (false);
	val.fVal = static_cast<float>(val.dVal);
	val.iVal = static_cast<int>(val.dVal);
	val.cVal = static_cast<char>(val.dVal);
	printValues(val);
	return (true);
}

bool  intHandler( std::string  &arg )	{

	char				dump;
	t_values			val;
	std::stringstream	sarg(arg);
	std::cout << "HANDLER : int" << std::endl;
	sarg >> val.iVal;
	if (sarg.fail() == true)
		std::cout << "Error: This result it undefined: the value passed as parameter has overflown!" << std::endl;
	sarg >> dump;
	sarg >> dump;
	if (sarg.eof() == false)
		return (false);
	val.fVal = static_cast<float>(val.iVal);
	val.dVal = static_cast<double>(val.iVal);
	val.cVal = static_cast<char>(val.iVal);
	printValues(val);
	return (true);
}

bool  charHandler( std::string  &arg )	{

	char				dump;
	t_values			val;
	std::stringstream	sarg(arg);
	std::cout << "HANDLER : char" << std::endl;
	if (arg.length() > 1)
		return (false);
	sarg >> val.cVal;
	if (sarg.fail() == true)
		std::cout << "Error: This result it undefined: the value passed as parameter has overflown!" << std::endl;
	sarg >> dump;
	sarg >> dump;
	if (sarg.eof() == false)
		return (false);
	val.fVal = static_cast<float>(val.cVal);
	val.dVal = static_cast<double>(val.cVal);
	val.iVal = static_cast<int>(val.cVal);
	printValues(val);
	return (true);
}

bool	regularDispatcher( std::string &arg )	{

	if ( arg.at(arg.length() - 1) == 'f' && arg.find_first_of("0123456789") != std::string::npos)
		return(floatHandler(arg));
	else if (arg.find('.') != std::string::npos)
		return(doubleHandler(arg));
	else if (arg.find_first_not_of("0123456789") != std::string::npos)
		return(charHandler(arg));
	else
		return(intHandler(arg));
}

int main( int ac, char **av ) 	{

	if (ac != 2)
	{
		std::cout << "This program takes exactly one string argument." << std::endl;
		return (1);
	}

	std::string		arg = av[1];
	std::string		specialInput[] = {	"+inf",	"-inf",	"+inff", "-inff", "nan", "nanf"	};
	bool 	 	(*handlerArr[])(std::string &) =
									 {	&infHandler, &infHandler, &infHandler, &infHandler, &nanHandler, &nanHandler, &regularDispatcher };
	size_t			nbSpecialInput = sizeof(specialInput) / sizeof(std::string);
	size_t			i = 0;

	while (i < nbSpecialInput && arg.compare(specialInput[i]) != 0)
		i++;
	if (handlerArr[i](arg) == false)
	{
		std::cout << "Could not extract the type from literal value." << std::endl;
		return (1);
	}
	return (0);
}
