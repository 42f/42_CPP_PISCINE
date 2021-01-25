# include "header.hpp"
# include <iostream>
# include <stdlib.h>

#include <string.h>

void * serialize(void)	{

	void * output;
	try {
		output = new char[outputSize] ;
	}
	catch ( std::exception & e) {
		std::cout << e.what() << std::endl;
		return (NULL);
	}
	memset(output, 0, sizeof(output));

	srand(time(NULL));
	for (size_t i = 0; i < char1End; i++)
		reinterpret_cast<char *>(output)[i] = (rand() % 2 == 0) ? rand() % 26 + 'a' : rand() % 10 + '0';

	reinterpret_cast<int *>(output)[2] = rand();

	for (size_t i = intEnd; i < char2End; i++)
		reinterpret_cast<char *>(output)[i] = (rand() % 2 == 0) ? rand() % 26 + 'a' : rand() % 10 + '0';

	return (output);
}

Data * deserialize(void * raw)	{

	Data * dataOutput = new Data;

	for (size_t i = 0; i < char1End; i++)
		dataOutput->s1.push_back(reinterpret_cast<char*>(raw)[i]);

	dataOutput->n = reinterpret_cast<int *>(raw)[2];

	for (size_t i = intEnd; i < char2End; i++)
		dataOutput->s2.push_back(reinterpret_cast<char*>(raw)[i]);

	return (dataOutput);
}

int		main( void ) 	{

	void * output = serialize();

	std::cout << RED_COLOR << std::endl << "[Serialize output: Dump Memory byte per byte]" << RESET_COLOR << std::endl;
	for (size_t i = 0; i < char1End; i++)
		std::cout << "[" << i << "] " << reinterpret_cast<char *>(output)[i] << std::endl;
	std::cout << "[int] " << reinterpret_cast<int *>(output)[2] << std::endl;
	for (size_t i = intEnd; i < char2End; i++)
		std::cout << "[" << i << "] " << reinterpret_cast<char *>(output)[i] << std::endl;

	Data * dataOutput = deserialize(output);

	std::cout << RED_COLOR << std::endl << "[Deserialize output: Print Data Structure]" << RESET_COLOR << std::endl;
	std::cout << "Data->s1 = [" << dataOutput->s1 << "]" << std::endl;
	std::cout << "Data->n  = [" << dataOutput->n << "]" << std::endl;
	std::cout << "Data->s2 = [" << dataOutput->s2 << "]" << std::endl;

	delete [] (reinterpret_cast<char *>(output));
	delete dataOutput;

	return (0);
}
