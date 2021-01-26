# include "header.hpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

void	functionChar(char &val)	{

	val = 42;
}
void	functionInt(int &val)	{

	val = 42;
}

int		main( void ) 	{
	{
		std::cout << RED_COLOR << "-------- [TEST WITH INT ARRAY : initial array] -----------" << RESET_COLOR << std::endl;

		int array[10] = { 0,1,2,3,4,5,6,7,8,9};
		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;


		std::cout << RED_COLOR << "[Iter with function template as argument (add 10)]" << RESET_COLOR << std::endl;
		iter<int>(array, 10, &function<int>);

		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;

		std::cout << RED_COLOR << "[Iter with regular function as argument (change value to 42)]" << RESET_COLOR << std::endl;
		iter<int>(array, 10, &functionInt);

		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;
	}
	{
		std::cout << std::endl << RED_COLOR << "-------- [TEST WITH CHAR ARRAY : initial array] -----------" << RESET_COLOR << std::endl;

		char array[10] = { 'a', 'b','c','d','e','f','g','h','i','j'};
		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;


		std::cout << RED_COLOR << "[Iter with function template as argument (add 10)]" << RESET_COLOR << std::endl;
		iter<char>(array, 10, &function<char>);

		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;

		std::cout << RED_COLOR << "[Iter with regular function as argument (change value to 42)]" << RESET_COLOR << std::endl;
		iter<char>(array, 10, &functionChar);

		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] - " << array[i] << std::endl;
	}


	return (0);
}
