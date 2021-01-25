#include <string>

struct Data {

	std::string s1;
	int n;
	std::string s2;
};

size_t const char1End = sizeof(char) * 8;
size_t const intEnd = sizeof(char) * 8 + sizeof(int);
size_t const char2End = sizeof(char) * 8 * 2 + sizeof(int);
size_t const outputSize = char2End;

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif
