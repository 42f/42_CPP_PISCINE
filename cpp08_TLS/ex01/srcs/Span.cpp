# include "Span.hpp"

#include <algorithm>    // std::sort
#include <vector>       // std::vector

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span::Span( void ) : _size(0)	{
}

Span::Span( unsigned int N ) : _size(N)	{

	try
	{
		this->_intArr = new int [N];
		this->_storedNumber = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span::Span( const Span & src )	{

	*this = src;
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span::~Span()	{

	if (this->_size != 0)
		delete [] this->_intArr;
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span &				Span::operator=( Span const & rhs )	{

	if ( this != &rhs )
	{
		if (this->_size != 0)
			delete [] this->_intArr;
		try
		{
			this->_intArr = new int [rhs._size];
			this->_storedNumber = rhs._storedNumber;
			for (unsigned int i = 0; i < this->_storedNumber; i++)
				this->_intArr[i] = rhs._intArr[i];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	return *this;
}

/*****
std::ostream &			operator<<( std::ostream & o, Span const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void	Span::printNumbers( void )	{

	for (unsigned int i = 0; i < this->_storedNumber; i++)
	std::cout << "[" << i << "] \t" << this->_intArr[i] << std::endl;
}

void	Span::addNumber( int const newNumber )	{

	if (this->_storedNumber < this->_size)
	{
		this->_intArr[this->_storedNumber] = newNumber;
		this->_storedNumber++;
	}
	else
		throw Span::SpanExceptionOutofCapacy();
}

int	Span::longestSpan( void )	{

	if (this->_storedNumber > 1)	{

		int min = *std::min_element(this->_intArr, this->_intArr + this->_storedNumber);
		int max = *std::max_element(this->_intArr, this->_intArr + this->_storedNumber);
		return (max - min);
	}
	else
		throw Span::SpanExceptionNoSpan();
}

int	Span::shortestSpan( void )	{

	if (this->_storedNumber > 1)	{

		std::vector<int> tmp (this->_intArr, this->_intArr + this->_storedNumbe);
		return (max - min);
	}
	else
		throw Span::SpanExceptionNoSpan();
}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

const char*	 Span::SpanExceptionOutofCapacy::what( void ) const throw()	{

	return ("The int storage is full.");
}

const char*	 Span::SpanExceptionNoSpan::what( void ) const throw()	{

	return ("Not enough ints stored to have a range.");
}

/* **********************************BVALETTE******************************** */
