#include <iostream>

class Abase	{
	public:
		virtual void attack( void ) = 0;
		virtual void sayHi( void );
		std::string		name;
};

class Ibase	{
	public:
		virtual void attack( void ) = 0;
		virtual void sayHi( void ) = 0;
		std::string		name;
};

class Der : public Ibase {
	public:
		virtual void attack( void ) { std::cout << "ATTAAACK" << std::endl; }
		void		 sayHi( void ) { std::cout << "coucou" << std::endl;}
};

int main()
{
	Der		a;
	Ibase  	*b = new Der;

	a.sayHi();
	a.attack();

	b->sayHi();
	b->attack();

}
