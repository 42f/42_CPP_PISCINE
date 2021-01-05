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
	*(this) = src;
	return ;
}

Fixed::Fixed( int const src )	{
	std::cout << "Int constructor called" << std::endl;
	Fixed::setRawBits(src<<this->_nbFractionalBits);
}

Fixed::Fixed( float const src )	{
	std::cout << "Float constructor called" << std::endl;

	std::cout << "FLOAT = ";
	Fixed::printToBinary(src);
	this->_value = roundf(src * (2<<(Fixed::_nbFractionalBits - 1)));
	std::cout << "fixed = ";
	Fixed::printToBinary(this->_value);
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
	return (this->getRawBits()>>this->_nbFractionalBits);
}

void					Fixed::printToBinary( float const src) {

	char				c;
	std::stringstream	output;
	int		tmp_src = *(int *)&src;

	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & tmp_src) != 0) ? '1' : '0';
		output << c;
		if (i == 0 || i == 8)
			output << '_';
	}
	std::cout << output.str() << std::endl;
}

void					Fixed::printToBinary( int const src) {

	char				c;
	std::stringstream	output;

	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & src) != 0) ? '1' : '0';
		output << c;
		if (i == 0 || i == 8)
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
