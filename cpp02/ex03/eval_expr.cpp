#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>

bool	opAdd(Fixed op1, Fixed op2, std::stringstream &opResult)	{ opResult << (op1 + op2); return true; }
bool	opSub(Fixed op1, Fixed op2, std::stringstream &opResult)	{ opResult << (op1 - op2); return true; }
bool	opMult(Fixed op1, Fixed op2, std::stringstream &opResult)	{ opResult << (op1 * op2); return true; }

bool	opDiv(Fixed op1, Fixed op2, std::stringstream &opResult)		{
	if (op2 == 0)
	{
		std::cout << "Error: Cannot divide by 0." << std::endl;
		return false;
	}
	opResult << (op1 / op2);
	return true;
}

size_t		wordCount(std::string const &str)	{

    size_t	wc = 0;
	size_t	cursorPos = 0;

	while ((cursorPos = str.find_first_not_of(" \t\n", cursorPos)) != std::string::npos)
	{
		wc++;
		cursorPos = str.find_first_of(" \t\n", cursorPos);
		if (cursorPos == std::string::npos)
			break ;
	}
	return (wc);
}

bool		operation(float &operand1, char &operatorSign, float &operand2, std::stringstream &opResult) 	{
	size_t const		nbOpe = 4;
	char const			ope[nbOpe] =
							{'*', '/', '+', '-'};
	bool 				(*f[nbOpe])(Fixed, Fixed, std::stringstream &) =
							{ opMult, opDiv, opAdd, opSub};

	size_t	i = 0;
	while (i < nbOpe && operatorSign != ope[i])
		i++;
	if (i < nbOpe)
		return (f[i](operand1, operand2, opResult));
	else
		return (false);
}

// std::string		operationProcess(std::ostringstream &operandsStream, std::ostringstream &operatorSignsStream)	{
std::string		operationProcess(std::string operands, std::string operatorSigns)	{

	size_t const		nbOpe = 2;
	char const			*ope[nbOpe] = {"*/", "+-"};
	size_t				operatorPos = 0;
	size_t				operand1Pos = 0;
	size_t				operand2Pos = 0;
	std::istringstream	value;
	float				op1;
	float				op2;
	char				opSign;
	std::stringstream	opResult;
	std::stringstream	op2Len;
	size_t				i = 0;

	while (i < nbOpe)
	{
		if ((operatorPos = operatorSigns.find_first_of(ope[i], operatorPos)) < operatorSigns.length())
		{
			opResult.str("");
			if (operatorPos != std::string::npos)
			{
				for (size_t i = 0; i < operatorPos; i++)
				{
					operand1Pos = operands.find_first_of(';', operand1Pos);
					if (operand1Pos != std::string::npos)
						operand1Pos++;
				}
				operand2Pos = operands.find_first_of(';', operand1Pos) + 1;
			}

			value.str(operands.substr(operand1Pos).c_str());
			value >> op1;
			if (value.rdstate() && std::istringstream::failbit)
				return("");
			value.str(operands.substr(operand2Pos).c_str());
			value >> op2;
			if (value.rdstate() && std::istringstream::failbit)
				return("");
			value.str(operatorSigns.substr(operatorPos).c_str());
			value >> opSign;
			if (value.rdstate() && std::istringstream::failbit)
				return("");

			op2Len << op2;
			operands.erase(operand1Pos , operand2Pos - operand1Pos + op2Len.str().length());
			operatorSigns.erase(operatorPos, 1);
			op2Len.str("");

			if (operation(op1, opSign, op2, opResult) == false)
				return ("");
			else
				operands.insert(operand1Pos, opResult.str());
		}
		if (operatorPos == operatorSigns.length() || operatorPos == std::string::npos)
			i++;
		else if (i == nbOpe)
			break ;
		operatorPos = 0;
		operand1Pos = 0;
		operand2Pos = 0;
	}
	return (opResult.str());
}

bool		checkAv(std::string const &av, size_t const &nbOfOpe)	{

	return (nbOfOpe % 2 != 0
		&& av.find_first_not_of("0123456789.+-*/() ") == std::string::npos
		&& av.find("..") == std::string::npos);
}

void			spaceAllOperators(std::string &av)	{
	size_t		operatorPos = 0;
	size_t		len;

	len = av.length();
	while ((operatorPos = av.find_first_of("+*/()", operatorPos)) <= len)
	{
		av.insert(operatorPos + 1, 1, ' ');
		av.insert(operatorPos, 1, ' ');
		operatorPos += 2;
		len = av.length();
	}
}

std::string		operationParser(std::string &av)	{

	std::istringstream	arg( av );
	std::ostringstream	operandsStream;
	std::ostringstream	operatorSignsStream;
	size_t				nbOfOpe;
	float				flValue;
	char				signValue;

	spaceAllOperators(av);
	nbOfOpe = wordCount(av.c_str());
	if (nbOfOpe == 1)
		return (av);
	if (checkAv(av, nbOfOpe) == false)
		return ("");
	for (int i = 0; i < ((int)nbOfOpe / 2) + 1; i++)
	{
		arg >> flValue;
		operandsStream << flValue << ";";
		if (i < ((int)nbOfOpe / 2))
		{
			arg >> signValue;
			operatorSignsStream << signValue;
		}
	}
	// if (operatorSignsStream.str().length() != (nbOfOpe / 2))
	// 	return ("");
	return(operationProcess(operandsStream.str(), operatorSignsStream.str()));
}

std::string		parenthesisParser(std::string &av)	{
	size_t			openParPos = 0;
	size_t			closeParPos = 0;
	std::string		resultStr;

	while ((openParPos = av.find_last_of('(', std::string::npos)) != std::string::npos)
	{
		if ((closeParPos = av.find_first_of(')', openParPos)) == std::string::npos)
			return ("");
		std::string	avSubStr(av.substr(openParPos + 1, closeParPos - openParPos - 1));
		resultStr = operationParser(avSubStr);
		if (resultStr.empty() == true)
			return("");
		av.erase(openParPos, closeParPos - openParPos + 1);
		av.insert(openParPos, resultStr);
		openParPos = 0;
		closeParPos = 0;
	}
	return (operationParser(av));
}

int			main( int const ac, char const **av )	{

	std::string			arg[ac];
	std::stringstream	opResult;

	if (ac != 2)
	{
		std::cout << "This program takes exactly one argument." << std::endl;
		return (1);
	}
	else
	{
		std::string avStr(av[1]);
		opResult.str(parenthesisParser(avStr));
	}
	if (opResult.str().empty() == true)
		std::cout << "Syntax Error in operations." << std::endl;
	else
		std::cout << opResult.str().c_str() << std::endl;
	return (0);
}
