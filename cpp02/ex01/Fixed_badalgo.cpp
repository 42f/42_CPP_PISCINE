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
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
	return ;
}

Fixed::Fixed( int const src )	{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(src<<(Fixed::_nbFractionalBits));
}

Fixed::Fixed( float const src )	{
	// std::cout << "Float constructor called" << std::endl;
	int		offset;
	int		tmp_value = 0;
	int		tmp_src = *(int *)&src;
	int		exp = 0;
	int		intPart = 0;

	// std::cout << "SRCS = ";
	// Fixed::printToBinary(src);

	if (src == 0)
	{
		this->setRawBits(0);
		return ;
	}
	exp = ((tmp_src & 0x7f800000)>>23) - 127;			//get exp value
	offset = 23 - Fixed::_nbFractionalBits - exp;	//compute bitshift needed
	tmp_value |= (tmp_src & 0x007fffff)>>offset;		//shift value to point position
	tmp_value |= 1<<(Fixed::_nbFractionalBits + exp);	//add leading 1
	intPart = (tmp_value & 0xFFFFFF00)>>(Fixed::_nbFractionalBits);		//get int part of fixed

	// std::cout << "intPa= ";
	// Fixed::printToBinary(intPart);
	// std::cout << "tmpV = ";
	// Fixed::printToBinary(tmp_value);

	if ((tmp_src & (1<<31)) != 0)
	{
		tmp_value &= ~(0xFFFFFF<<Fixed::_nbFractionalBits);		//if src is neg, negate int part
	// std::cout << "tmpV = ";
	// Fixed::printToBinary(tmp_value);
		tmp_value |= (intPart * -1)<<(Fixed::_nbFractionalBits);		//if src is neg, negate int part
		if ((int)src == 0)
			tmp_value |= 1<<31;
	}

	// std::cout << "tmpV = ";
	// Fixed::printToBinary(tmp_value);
	this->setRawBits( tmp_value );

	// std::cout << "toFL = ";
	// Fixed::printToBinary(this->toFloat());
	// std::cout << "toInt= ";
	// Fixed::printToBinary(this->toInt());
	// std::cout << "exp = " << exp << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
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
	bool	sign = 0;
	int		src = this->getRawBits();
	int		output = 0;
	int		firstBit = 30;
	short	exp;

	if (this->getRawBits() == 0)
		return (0);
	// std::cout << std::endl << "toFloat() before = ";
	// Fixed::printToBinary(src);
	if ((src & (1<<31)) != 0)
	{
		sign = 1;
		// std::cout << "toFloat() during = ";
		// Fixed::printToBinary(((src>>Fixed::_nbFractionalBits) * -1)<<Fixed::_nbFractionalBits);
		int		intPart = 0;
		intPart = (((src>>Fixed::_nbFractionalBits) * -1)<<Fixed::_nbFractionalBits);
		// std::cout << "toFloat() intPart= ";
		// Fixed::printToBinary(intPart);

		src &= ~(0xFFFFFF<<Fixed::_nbFractionalBits);
		// std::cout << "toFloat() CLEAN  = ";
		// Fixed::printToBinary(src);

		src |= intPart;
		// std::cout << "toFloat() after  = ";
		// Fixed::printToBinary(src);
	}
	while (firstBit > 0 && (src & 1<<firstBit) == 0)
		firstBit--;
	// std::cout << std::endl << "toFL1= ";
	// Fixed::printToBinary(src);
	src &= ~(1<<firstBit);
	// std::cout << "toF15= ";
	// Fixed::printToBinary(src);
	exp = firstBit - Fixed::_nbFractionalBits + 127;
	// std::cout << "exp in TOFLOAT ========== "<< exp << "first bit == " << firstBit << std::endl;
	// Fixed::printToBinary(exp);
	output |= exp<<23;
	// std::cout << "toFL2= ";
	// Fixed::printToBinary(output);
	output |= src<<(23 - firstBit);

	// std::cout << "toFL3= ";
	// Fixed::printToBinary(output);
	output |= sign<<31;
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
