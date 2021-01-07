#include "Fixed.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int	Fixed::_nbFractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
	return ;
}

Fixed::Fixed( int const src )	{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(src<<(Fixed::_nbFractionalBits));
}

Fixed::Fixed( float const src )	{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(src * (1<<Fixed::_nbFractionalBits)));
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
	return((float)this->getRawBits() / (1<<Fixed::_nbFractionalBits));
}

int						Fixed::toInt( void ) const		{
	return((int)roundf(this->toFloat()));
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

/*
**	---------- PRINTER ---------------------
*/


void					Fixed::printToBinary( float const src) const {

	char				c;
	std::stringstream	output;
	int		tmp_src = *(int *)&src;

	output << "float  	 = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & tmp_src) != 0) ? '1' : '0';
		output << c;
		if ((i + 1) % 4 == 0)
			output << ' ';
	}
	std::cout << output.str() << std::endl;
}

void					Fixed::printToBinary( int const src )  const {

	char				c;
	std::stringstream	output;

	output << "int    	 = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & src) != 0) ? '1' : '0';
		output << c;
		if ((i + 1) % 4 == 0)
			output << ' ';
	}
	std::cout << output.str() << std::endl;
}

void					Fixed::printToBinary( Fixed const *src) const {

	char				c;
	std::stringstream	output;

	output << "-fixed   = ";
	for (int i = 0; i < 32; i++)
	{
		c = (((1<<(31 - i)) & src->_value) != 0) ? '1' : '0';
		output << c;
		if ((i + 1) % 4 == 0)
			output << ' ';
	}
	std::cout << output.str() << std::endl;
}

/* ************************************************************************** */
