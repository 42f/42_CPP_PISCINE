# include "header.hpp"
# include <iostream>
# include <stdlib.h>


void * serialize(void)	{

	size_t outputSize = sizeof(char) * 8 + sizeof(int) * 1 + sizeof(char) * 8;
	void * output = new (outputSize);

	srand = static_cast<unsigned int>(&output);
	for (int i = 0; i < 8; i++)
		*(output + (sizeof(char) * i)) = static_cast<char>((rand() % 26) + 'a');
	for (int i = 0; i < 8; i++)
		std::cout << *(output + (sizeof(char) * i)) << std::endl;
	 
}

//Data * deserialize(void * raw)	{


//}

int		main( void ) 	{

	serialize();

	return (0);
}
