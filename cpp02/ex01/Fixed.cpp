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
	this->setRawBits(src<<(Fixed::_nbFractionalBits - 1));
}

Fixed::Fixed( float const src )	{
	std::cout << "Float constructor called" << std::endl;
	int		offset;
	int		tmp_value = 0;
	int		tmp_src = *(int *)&src;
	int		exp = 0;

	if (src == 0)
	{
		this->setRawBits(0);
		return ;
	}
	// int		a = 0xffffffff;
	// std::cout << "tmp     = ";
	// Fixed::printToBinary(a);
	// a = (a & 0x007fffff)>>(23 - Fixed::_nbFractionalBits - 2 + 1);
	// std::cout << "tmp     = ";
	// Fixed::printToBinary(a);
	// a |= 1<<(Fixed::_nbFractionalBits + 2 - 1);
	// std::cout << "tmp     = ";
	// Fixed::printToBinary(a);





	exp = ((tmp_src & 0x7f800000)>>23) - 127;
	offset = 23 - Fixed::_nbFractionalBits - exp + 1;
	tmp_value = (tmp_src & 0x007fffff)>>offset;
	// std::cout << "tmpV0= ";
	// Fixed::printToBinary(tmp_value);
	tmp_value |= 1<<(Fixed::_nbFractionalBits + exp - 1);
	this->setRawBits( tmp_value );

	std::cout << "SRCS = ";
	Fixed::printToBinary(src);
	std::cout << "tmpS = ";
	Fixed::printToBinary(tmp_src);
	std::cout << "tmpV1= ";
	Fixed::printToBinary(tmp_value);
	std::cout << "toFL = ";
	Fixed::printToBinary(this->toFloat());
	std::cout << "toInt= ";
	Fixed::printToBinary(this->toInt());
	std::cout << "Fixd = ";
	Fixed::printToBinary(this);
	std::cout << "exp = " << exp << std::endl;
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
	// o << std::setw(16);
	// o << std::setprecision(6);
	// o << std::fixed;
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float					Fixed::toFloat( void ) const	{
	int		src = this->getRawBits();
	int		output = 0;
	int		firstBit = 31;
	short	exp;

	if (this->getRawBits() == 0)
		return (0);
	while (firstBit > 0 && (src & 1<<firstBit) == 0)
		firstBit--;
	// std::cout << std::endl << "toFL1= ";
	// Fixed::printToBinary(src);
	src &= ~(1<<firstBit);
	// std::cout << "toF15= ";
	// Fixed::printToBinary(src);
	exp = firstBit - Fixed::_nbFractionalBits + 127 + 1;
	// std::cout << "exp in TOFLOAT ========== "<< exp << "first bit == " << firstBit << std::endl;
	// Fixed::printToBinary(exp);
	output |= exp<<23;
	// std::cout << "toFL2= ";
	// Fixed::printToBinary(output);
	output |= src<<(23 - firstBit);

	// std::cout << "toFL3= ";
	// Fixed::printToBinary(output);
	if ((src & (1<<31)) == 1)
		output |= 1<<31;
	return (*(float *)&output);
}

int						Fixed::toInt( void ) const		{
	return (roundf(this->toFloat()));
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

	output << "->fixed   = ";
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
