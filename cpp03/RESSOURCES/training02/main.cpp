#include <iostream>
#include <string>


class Base
{
	public:
		Base(std::string name) : _name(name), _i(0), _j(0)	 {
			std::cout << "Ctor Base " << std::endl;
			std::cout << "i = " << this->getValueI() << std::endl;
			std::cout << "j = " << this->getValueJ() << std::endl;
			std::cout << "i = " << this->_i << std::endl;
			std::cout << "j = " << this->_j << std::endl;
		};

		virtual int	 	getValueI( void ) const	{
			return(this->_i);
		};
		virtual int	 	getValueJ( void ) const	{
			return(this->_j);
		};

	protected:
		virtual void 	setValueI( int value )	{
			this->_i = value;
		};
		virtual void 	setValueJ( int value )	{
			this->_j = value;
		};

	private:
		std::string const 	_name;
		int 				_i;
		int 				_j;

};

class D1 : virtual public Base
{

	public:
		D1(std::string name) : Base(name), _i(10000000), _j(20000000) {
			this->setValueI(424242);
			// this->setValueJ(424242);
			std::cout << "Ctor D1 " << std::endl;
			std::cout << "i = " << this->getValueI() << std::endl;
			std::cout << "j = " << this->getValueJ() << std::endl;
			std::cout << "i = " << this->_i << std::endl;
			std::cout << "j = " << this->_j << std::endl;
		};

	protected:

		int 				_i;
		int 				_j;
};

class D2 : virtual public Base
{

	public:
		D2(std::string name) : Base(name), _i(32), _j(33) {
			// this->setValueI(999);
			// this->setValueJ(999);
			std::cout << "Ctor D2 " << std::endl;
			std::cout << "i = " << this->getValueI() << std::endl;
			std::cout << "j = " << this->getValueJ() << std::endl;
			std::cout << "i = " << this->_i << std::endl;
			std::cout << "j = " << this->_j << std::endl;
		};

	protected:

		int 				_i;
		int 				_j;

};

class Z1 : virtual public Base, virtual public D1, virtual public D2
{

	public:
		Z1(std::string name) :  Base(name), D1(name), D2(name) {

			std::cout << "Ctor ---------" << std::endl;
			std::cout << "getvalue() d1 i = " << D1::getValueI() << std::endl;
			std::cout << "getvalue() d1 j = " << D1::getValueJ() << std::endl;
			std::cout << "getvalue() d2 i = " << D2::getValueI() << std::endl;
			std::cout << "getvalue() d2 j = " << D2::getValueJ() << std::endl;
			std::cout << "d1 i = " << D1::_i << std::endl;
			std::cout << "d1 j = " << D1::_j << std::endl;
			std::cout << "d2 i = " << D2::_i << std::endl;
			std::cout << "d2 j = " << D2::_j << std::endl;
			std::cout << "--------------" << std::endl;
			this->setValueI(D1::_i); //    <----- should equal 424242, but equals 999
			this->setValueJ(D2::_j);
		};
};

int main ( void )	{

	// Base	a("marcel");
	// D1	 	d1("d");
	// D2	 	d2("d");
	Z1	 	z1("d");

	// std::cout << "a  - " << a.getValueI() << std::endl;	// <--- show 0
	// std::cout << "a  - " << a.getValueJ() << std::endl;	// <--- show 0

	// std::cout << "d1 - " << d1.getValueI() << std::endl;	// <--- show 424242
	// std::cout << "d1 - " << d1.getValueJ() << std::endl;	// <--- show 424242

	// std::cout << "d2 - " << d2.getValueI() << std::endl;	// <--- show 999
	// std::cout << "d2 - " << d2.getValueJ() << std::endl;	// <--- show 999

	std::cout << "z1 - " << z1.getValueI() << std::endl;	// <--- show 999 should show 424242
	std::cout << "z1 - " << z1.getValueJ() << std::endl;	// <--- show 999

	return (0);
}
