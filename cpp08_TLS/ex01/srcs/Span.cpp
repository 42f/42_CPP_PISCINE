# include "Span.hpp"

# include <algorithm>    // std::sort
# include <limits>

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span::Span( void ) : _sizeMax(0)	{
}

Span::Span( unsigned int N ) : _sizeMax(N)	{

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

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Span &				Span::operator=( Span const & rhs )	{

	if ( this != &rhs )
	{
		this->_intStorage = rhs._intStorage;
		this->_sizeMax = rhs._sizeMax;
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

	for (std::vector<int>::iterator it = this->_intStorage.begin();
		it != this->_intStorage.end(); ++it)
	std::cout << "\t" << *it << std::endl;
	// std::cout << "[" << it << "] \t" << *it << std::endl;
}

void	Span::addNumber( int const newNumber )	{

	if (this->_intStorage.size() < this->_sizeMax)
		this->_intStorage.push_back(newNumber);
	else
		throw Span::SpanExceptionOutofCapacy();
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end )	{

	std::vector<int>::iterator	endCopy = end;

	if (end - begin + this->_intStorage.size() > this->_sizeMax)
		endCopy = begin + this->_sizeMax - this->_intStorage.size();

	for (std::vector<int>::iterator it = begin; it != endCopy; it++)
		this->_intStorage.push_back(*it);

	if (end != endCopy)
		throw Span::SpanExceptionOutofCapacy();
}

unsigned int	Span::longestSpan( void )	{

	if (this->_intStorage.size() > 1)	{

		unsigned int min = *std::min_element(this->_intStorage.begin(), this->_intStorage.end());
		unsigned int max = *std::max_element(this->_intStorage.begin(), this->_intStorage.end());
		return (max - min);
	}
	else
		throw Span::SpanExceptionNoSpan();
}

unsigned int	Span::shortestSpan( void )	{

	if (this->_intStorage.size() > 1)	{

		std::vector<int>	tmp = this->_intStorage;
		unsigned int		shortestSpan = std::numeric_limits<unsigned int>::max();
		unsigned int		tmpSpan;

		std::sort(tmp.begin(), tmp.end());

		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it)
		{
			if ((tmpSpan = *(it + 1) - *(it)) < shortestSpan)
				shortestSpan = tmpSpan;
		}
		return(shortestSpan);
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
