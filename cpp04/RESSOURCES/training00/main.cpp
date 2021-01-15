
#include <iostream>

class Character	{
	public:

	Character()	{
		this->nd = 42;
	}

	virtual void sayHello(std::string const &target)	{
		std::cout << "<3 Hellowww " << target << std::endl;
	};

	int		nd;
	virtual ~Character() {};
};

class Warrior : public Character	{
	public:

	virtual void sayHello(std::string const &target)	{
		std::cout << "Fuck you " << target << std::endl;
	};

	virtual ~Warrior() {};
};

class Cat	{

};




int		main( void )	{

	Warrior		*a = new Warrior();
	Character	*b = new Warrior();

	a->sayHello("marcus");
	b->sayHello("42");

	std::cout << a->nd << std::endl;

	delete a;
	delete b;
}
