#include <iostream>


class Animal	{

	public:
	Animal(int age) : _age(age) {
		this->_index = 10;
	};
	~Animal() { std::cout << "ANIMAL DIED " << this->getIndex() << std::endl;};

	int			getAge( void ) { return this->_age; };
	int			getIndex( void ) { return this->_index; };
	protected:

	protected:

	int _age;
	int	_index;
};

class Dog : public Animal	{

	public:
	Dog(int age) : Animal(age) { this->_index = 42;	};
	~Dog() { std::cout << this->getIndex() << " died at the age of " << this->getAge() << std::endl; }

	private:

};

int		main( void )	{

	Animal	loutre(0);
	Dog doggy1(12);


	return (0);
}
