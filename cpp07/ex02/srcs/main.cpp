# include "Array.hpp"
# include "Array.cpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) 	{

	std::cout << RED_COLOR << "-------- [No parameter constructor] -----------" << RESET_COLOR << std::endl;
	{
		Array<int>	arr;
		try {
			std::cout << static_cast<int>(arr[0]) << std::endl;
		}
		catch (const std::exception & e)	{
			std::cout << "Can't access array" << std::endl;
		}
	}
	std::cout << RED_COLOR << "-------- [Int arr of 10] -----------" << RESET_COLOR << std::endl;
	{
		Array<int>	arr(10);

		for (size_t i = 0; i < 10; i++)
			arr[i] = 0;
		arr[2] = 42;
		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] "<< arr[i] << std::endl;

		try
		{
			arr[42] = 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "GOT AN EXCEPTION while trying to access arr[42]! -> " << e.what() << std::endl;
		}
	}
	std::cout << RED_COLOR << "-------- [float array of 10] -----------" << RESET_COLOR << std::endl;
	{
		Array<float>	arr(10);

		for (size_t i = 0; i < 10; i++)
			arr[i] = 0;
		arr[4] = 42.25f;
		for (size_t i = 0; i < 10; i++)
			std::cout << "[" << i << "] "<< arr[i] << std::endl;
	}
	std::cout << RED_COLOR << "-------- [2 char array of 10 and 12] -----------" << RESET_COLOR << std::endl;
	{
		Array<char>	arr(10);
		Array<char>	arr2(12);

		for (size_t i = 0; i < 10; i++)
			arr[i] = '_';
		arr[4] = 'X';
		for (size_t i = 0; i < 10; i++)
			std::cout << "arr 1 [" << i << "] "<< arr[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 12; i++)
			std::cout << "arr 2 [" << i << "] "<< arr2[i] << std::endl;

		std::cout << RED_COLOR << "-------- [ arr1 = arr2 ] -----------" << RESET_COLOR << std::endl;

		arr2 = arr;

		for (size_t i = 0; i < 10; i++)
				std::cout << "arr 1 [" << i << "] "<< arr[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 10; i++)
			std::cout << "arr 2 [" << i << "] "<< arr2[i] << std::endl;

		std::cout << RED_COLOR << "-------- [ chaning arr1 will not affect arr2 ] -----------" << RESET_COLOR << std::endl;

		for (size_t i = 0; i < 10; i++)
			arr[i] = '@';
		arr[5] = '_';

		for (size_t i = 0; i < 10; i++)
			std::cout << "arr 1 [" << i << "] "<< arr[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 10; i++)
			std::cout << "arr 2 [" << i << "] "<< arr2[i] << std::endl;
	}
	return (0);
}
