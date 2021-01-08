#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

Fixed	opAdd(Fixed op1, Fixed op2)		{ return op1 + op2; }
Fixed	opSub(Fixed op1, Fixed op2)		{ return op1 - op2; }
Fixed	opMult(Fixed op1, Fixed op2)	{ return op1 * op2; }
Fixed	opDiv(Fixed op1, Fixed op2)		{ return op1 / op2; }

#define OUT	0
#define IN	1

size_t		wordCount(char const *str)	{

	bool	state = OUT;
    size_t	wc = 0;
	int		i = 0;

	while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            wc++;
        }
		i++;
    }
	return (wc);
}

Fixed		operation(float operand1, char operatorSign, float operand2)	{
	size_t const		nbOpe = 4;
	char const			ope[nbOpe] = {'*', '/', '+', '-'};
	Fixed				(*f[nbOpe])(Fixed, Fixed) =	{ opMult, opDiv, opAdd, opSub};
	Fixed				output;

	size_t	i = 0;
	while (i < nbOpe && operatorSign != ope[i])
		i++;
	if (i < nbOpe)
		output = f[i](operand1, operand2);
	std::cout << operand1 << operatorSign << operand2 << " = " << output << std::endl;
	return (output);
}

void		interpretorProcess(std::ostringstream &operandsStream, std::ostringstream &operatorSignsStream)	{

	size_t const		nbOpe = 4;
	char const			ope[nbOpe] = {'*', '/', '+', '-'};
	std::string			operatorSigns = operatorSignsStream.str();
	std::string			operands = operandsStream.str();
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
		// std::cout << "\t\t\tbe (" << operands.c_str() << ")  " << operatorSigns.c_str()  << std::endl;
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
			value.str(operands.substr(operand2Pos).c_str());
			value >> op2;
			value.str(operatorSigns.substr(operatorPos).c_str());
			value >> opSign;

			op2Len << op2;
			// std::cout << "DEBUG " << operand2Pos - operand1Pos << " . " << operand1Pos << " . " << operand2Pos << " . len " << op2Len.str().length() << std::endl;
			operands.erase(operand1Pos , operand2Pos - operand1Pos + op2Len.str().length());
			operatorSigns.erase(operatorPos, 1);
			op2Len.str("");

			opResult << (operation(op1, opSign, op2).toFloat());
			operands.insert(operand1Pos, opResult.str());
		}
		if (operatorPos == operatorSigns.length() || operatorPos == std::string::npos)
			i++;
		else if (i == nbOpe)
			break ;
		operatorPos = 0;
		operand1Pos = 0;
		operand2Pos = 0;
		// std::cout << "\t\t\taf (" << operands.c_str() << ")  " << operatorSigns.c_str()  << std::endl;
	}
	if (opResult.str().empty() == false)
	{
		std::cout << std::fixed;
		std::cout << opResult.str().c_str() << std::endl;
	}
}

bool		checkAv(std::string av, size_t nbOfOpe)	{

	return (nbOfOpe % 2 != 0 && av.find_first_not_of("0123456789+-*/ ") == std::string::npos);
}

void		interpretorPreProcess(std::string av)	{

	std::istringstream	arg( av );
	std::ostringstream	operandsStream;
	std::ostringstream	operatorSignsStream;
	size_t				nbOfOpe = wordCount(av.c_str());
	float				flValue;
	char				signValue;

	if (checkAv(av, nbOfOpe) == false)
	{
		std::cout << "Syntax Error in operations." << std::endl;
		return ;
	}
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
	interpretorProcess(operandsStream, operatorSignsStream);
}

int			main( int ac, char **av )	{

	std::string		arg[ac];

	if (ac != 2)
	{
		std::cout << "This program takes exactly one argument." << std::endl;
		return (1);
	}
	else
		interpretorPreProcess(av[1]);
	return (0);
}
