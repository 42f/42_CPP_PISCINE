# include "Span.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

# include <limits>
# include <stdlib.h>
# include <algorithm>

void	randval( int &a )	{

	a = rand() % 1000;
}

void	printval( int &a )	{

	std::cout << a << "_";
}

int main( void ) 	{

	std::cout << RED_COLOR << "~~~~~~~~~~~MAIN FROM SUBJECT~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{

	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	}
	std::cout << RED_COLOR << "~~~~~~~~~~END MAIN FROM SUBJECT~~~~~~~~" << RESET_COLOR << std::endl << std::endl;

	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~    MAIN BVALETTE #1  ~~~~~~~~" << RESET_COLOR << std::endl;
	{

		std::cout << std::endl << RED_COLOR << "[ Instanciate a span with 25 ints capacity ]" << RESET_COLOR << std::endl;
		Span sp = Span(25);

		std::cout << std::endl << RED_COLOR << "[ Add 25 numbers and print ]" << RESET_COLOR << std::endl;
		srand(time(NULL));
		for (int i = 0; i < 25; i++)
			sp.addNumber(rand());

		sp.printNumbers();

		std::cout << std::endl << RED_COLOR << "[ Add one too many number ]" << RESET_COLOR << std::endl;
		try	{
			sp.addNumber(99);
		}
		catch (const std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << RED_COLOR << "[ Calling functions longestSpan and shortestSpan ]" << RESET_COLOR << std::endl;
		std::cout << "LONGUEST = " << sp.longestSpan() << std::endl;
		std::cout << "SHORTEST = " << sp.shortestSpan() << std::endl;
	}

	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~    MAIN BVALETTE #2    ~~~~~~~~" << RESET_COLOR << std::endl;

	{

		std::cout << std::endl << RED_COLOR << "[ Instanciate a span with 4 ints capacity ]" << RESET_COLOR << std::endl;
		Span sp = Span(4);

		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::max() + 1);
		sp.addNumber(42);
		sp.addNumber(42);

		std::cout << std::endl << RED_COLOR << "[ Calling functions longestSpan and shortestSpan ]" << RESET_COLOR << std::endl;
		std::cout << "LONGUEST = " << sp.longestSpan() << std::endl;
		std::cout << "SHORTEST = " << sp.shortestSpan() << std::endl;
		std::cout << std::endl << RED_COLOR << "[ Longuest should equal unsigned int max and shorter 0 ]" << RESET_COLOR << std::endl;

	}
	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~    MAIN BVALETTE #2    ~~~~~~~~" << RESET_COLOR << std::endl;

	{

		std::cout << std::endl << RED_COLOR << "[ Instanciate a span with ZERO ints capacity ]" << RESET_COLOR << std::endl;
		Span sp = Span(0);
		std::cout << std::endl << RED_COLOR << "[ Calling functions longestSpan and shortestSpan ]" << RESET_COLOR << std::endl;
		try
		{
			std::cout << "LONGUEST = " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "SHORTEST = " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}


	}

	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~    MAIN BVALETTE #3    ~~~~~~~~" << RESET_COLOR << std::endl;

	{
		std::cout << std::endl << RED_COLOR << "[ Instanciate a VECTOR with 10000 ints capacity ]" << RESET_COLOR << std::endl;
		std::vector<int>	vInt(1000000);

		srand(time(NULL));
		std::for_each(vInt.begin(), vInt.end(), &randval);
		std::cout << std::endl << RED_COLOR << "[ Instanciate a span with 10000 ints capacity ]" << RESET_COLOR << std::endl;
		Span sp = Span(1000000);
		std::cout << std::endl << RED_COLOR << "[ Add 3 ints in Span ]" << RESET_COLOR << std::endl;

		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		std::cout << std::endl << RED_COLOR << "[ Add the 1000000 ints by passing range of iterators, should return exception ]" << RESET_COLOR << std::endl;
		try {
			sp.addNumber(vInt.begin(), vInt.end());
		}
		catch ( const std::exception & e)	{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << RED_COLOR << "[ Calling functions longestSpan and shortestSpan ]" << RESET_COLOR << std::endl;
		std::cout << "LONGUEST = " << sp.longestSpan() << std::endl;
		std::cout << "SHORTEST = " << sp.shortestSpan() << std::endl;
		// sp.printNumbers();
	}

	return 0;
}
