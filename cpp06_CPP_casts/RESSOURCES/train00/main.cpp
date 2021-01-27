

# include <iostream>
class Parent					{};
class Child1 : public Parent	{};
class Child2 : public Parent	{};


int main ( void )	{

	Child1 a;

	Parent * b = &a;

	return (0);
}
