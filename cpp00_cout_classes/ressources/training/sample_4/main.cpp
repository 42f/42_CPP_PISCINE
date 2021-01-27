#include <iostream>
#include "Sample.class.hpp"

int main(void) {
	Sample instance;

	instance.publicBar();
	std::cout << "IN MAIN [value = " << instance.publicFoo << "]" <<std::endl;
	return (0);
}
