#include "Fixed.hpp"
#include <cmath>
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int	Fixed::_nbFractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits( src.getRawBits() );
	Fixed::printToBinary(this);
	return ;
}

Fixed::Fixed( int const src )	{
	std::cout << "Int constructor called" << std::endl;
	int		tmp_value = 0;

	tmp_value = src<<Fixed::_nbFractionalBits;
	if (src < 0)
		tmp_value |= 1<<31;
	this->setRawBits(tmp_value);
	Fixed::printToBinary(src);
	Fixed::printToBinary(this);
}

Fixed::Fixed( float const src )	{
	std::cout << "Float constructor called" << std::endl;

	int		tmp_src = *(int *)&src;
	Fixed::printToBinary(src);
	if (src < 0)
	{
		this->_value |= (((int)src * -1)<<8);
		this->_value |= 1<<31;
	}
	else
	{
		this->_value |= (((int)src)<<8);
		this->_value |= 0<<31;
	}
	this->_value |= (tmp_src & 0x7F0000)>>16;

	Fixed::printToBinary(this);
	// this->setRawBits( tmp_value );
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setRawBits(rhs.getRawBits());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float					Fixed::toFloat( void ) const	{
	return(this->getRawBits());
}

int						Fixed::toInt( void ) const		{
	int		output;

	output = (0x7FFFFF00 & this->getRawBits())>>8;
	if ((1<<31 & this->getRawBits()) != 0)
		output *= -1;
	return (output);
	// return (this->getRawBits()>>this->_nbFractionalBits);
}

void					Fixed::printToBinary( float const src) {

	char				c;
	std::stringstream	output;
	int		tmp_src = *(int *)&src;

	output << "float  	 = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & tmp_src) != 0) ? '1' : '0';
		output << c;
		if (i == 0 || i == 8)
			output << '_';
	}
	std::cout << output.str() << std::endl;
}

void					Fixed::printToBinary( int const src ) {

	char				c;
	std::stringstream	output;

	output << "int    	 = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & src) != 0) ? '1' : '0';
		output << c;
		if (i == 0 || i == 23)
			output << ' ';
	}
	std::cout << output.str() << std::endl;
}

void					Fixed::printToBinary( Fixed const *src) {

	char				c;
	std::stringstream	output;

	output << "->fixed  = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & src->_value) != 0) ? '1' : '0';
		output << c;
		if (i == 0 || i == 23)
			output << '_';
	}
	std::cout << output.str() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int						Fixed::getRawBits( void ) const	{
	return (this->_value);
}

void					Fixed::setRawBits( int const raw )	{
	this->_value = raw;
}


/* ************************************************************************** */
