#include <iostream>
#include <string>

int		main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout.width(18);
	std::cout << std::left << "With pointer:";
	std::cout << *str_ptr << std::endl;
	std::cout.width(18);
	std::cout << std::left << "With reference:";
	std::cout << str_ref << std::endl;

	return (0);
}
