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
	char const			ope[nbOpe] = {'+', '-', '*', '/'};
	Fixed				(*f[nbOpe])(Fixed, Fixed) =	{ opAdd, opSub, opMult, opDiv};
	Fixed				output;

	size_t	i = 0;
	while (i < nbOpe && operatorSign != ope[i])
		i++;
	if (i < nbOpe)
		output = f[i](operand1, operand2);
	std::cout << operand1 << operatorSign << operand2 << " = " << output << std::endl;
	return (output);
}

/*
		std::cout << "__________________" << std::endl;
		std::cout << operands.c_str() << std::endl;
		std::cout << operatorSigns.c_str() << std::endl;

		std::cout << "data --> " << op1 << " " << opSign << " " << op2 << std::endl;
		std::cout << "RESULT ==> " << opResult.str().c_str() << std::endl;
*/

void		interpretorProcess(std::ostringstream &operandsStream, std::ostringstream &operatorSignsStream)	{

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

	while ((operatorPos = operatorSigns.find_first_of('*', operatorPos)) < operatorSigns.length())
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
		value.str(operands.substr(operand2Pos).c_str());
		value >> op2;
		value.str(operatorSigns.substr(operatorPos).c_str());
		value >> opSign;

		operands.erase(operand1Pos, operand2Pos - operand1Pos + 1);
		operatorSigns.erase(operatorPos, 1);

		opResult << (operation(op1, opSign, op2).toFloat()) ;

		operands.insert(operand1Pos, opResult.str());

		if (operatorPos == operatorSigns.length() - 1)
			break ; 		// change sign here
		else
			operatorPos = 0;
		operand1Pos = 0;
		operand2Pos = 0;
	}
}

void		interpretorPreProcess(std::string av)	{

	std::istringstream	arg( av );
	std::ostringstream	operandsStream;
	std::ostringstream	operatorSignsStream;
	size_t				nbOfOpe = wordCount(av.c_str());
	float				flValue;
	char				signValue;

	if (nbOfOpe % 2 == 0)
	{
		std::cout << "Syntax Error in operations. (Please note this program does not manage () and ^. " << std::endl;
		return ;
	}
	for (int i = 0; i < ((int)nbOfOpe / 2) + 1; i++)
	{
		arg >> flValue;
		operandsStream << flValue << ";";
		arg >> signValue;
		operatorSignsStream << signValue;
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
