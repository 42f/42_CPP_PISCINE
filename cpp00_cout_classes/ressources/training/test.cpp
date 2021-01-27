#include <iostream>

int a = 1;

namespace Foo
{
	int a = 4;
}

namespace Bar = Foo;

int main(void)
{
	char buff[512];

	std::cout << Foo::a << std::endl;
	std::cin >> buff;
	std::cout << "[" << buff << "]" << std::endl;
}
