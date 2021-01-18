# include <iostream>
# include <stdexcept>

void test1( void )	{

	try {
		std::cout << "Block try..." << std::endl;
		if (1 == 1)
			throw std::exception();
		else
			std::cout << "unreal" << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test2( void )	{

	throw std::exception();
}

void test3( void )	{
	try
	{
		test2();
	}
	catch (std::exception & e)
	{
		std::cout << "inside test 3 catched !" << e.what() << std::endl;
	}
}

void test4( void )	{

	class COUCOUexception : public std::exception
	{
		public :
			virtual const char* what () const throw()	{
				return ("Probleme de COUCOUCOCUCOUCUCOUCOU");
			}
	};

	try
	{
		test2();
	}
	catch (COUCOUexception &e)
	{
		std::cout << "after test 2() Catched exception: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "after test 2() Catched regular exception: " << e.what() << std::endl;
	}

	try	{
		throw COUCOUexception();
	}
	catch (COUCOUexception &e)
	{
		std::cout << "after test inside test4() Catched exception: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "after test inside test4() Catched regular exception: " << e.what() << std::endl;
	}
}


int main( void )	{

	test1();
	test3();
	test4();

}
