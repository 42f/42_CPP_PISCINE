# include "Span.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	std::cout << RED_COLOR << "~~~~~~~~~~MAIN FROM SUBJECT~~~~~~~~~~~" << RESET_COLOR << std::endl;
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
	std::cout << std::endl << RED_COLOR << "[ MAIN BVALETTE ]" << RESET_COLOR << std::endl;
	{

		std::cout << std::endl << RED_COLOR << "[ Instanciate a span with 25 ints capacity ]" << RESET_COLOR << std::endl;
		Span sp = Span(25);

		sp.addNumber(-5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);

		std::cout << std::endl << RED_COLOR << "[ Add 5 numbers and print ]" << RESET_COLOR << std::endl;
		sp.printNumbers();
		std::cout << std::endl << RED_COLOR << "[ Add 20 more numbers and print ]" << RESET_COLOR << std::endl;
		for (int i = 0; i < 19; i++)
			sp.addNumber(2);

		sp.addNumber(100);
		sp.printNumbers();

		std::cout << std::endl << RED_COLOR << "[ Add one too many number ]" << RESET_COLOR << std::endl;
		try	{
			sp.addNumber(99);
		}
		catch (const Span::SpanExceptionOutofCapacy & e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "LONGUEST = " << sp.longestSpan() << std::endl;
		std::cout << "SHORTEST = " << sp.shortestSpan() << std::endl;
	}

	return 0;
}
