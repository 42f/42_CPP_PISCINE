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
	this->setRawBits(0);
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

Fixed::Fixed( int const src )	{
	this->setRawBits(src<<(Fixed::_nbFractionalBits));
}

Fixed::Fixed( float const src )	{
	this->setRawBits(roundf(src * (1<<Fixed::_nbFractionalBits)));
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

bool	Fixed::operator==( Fixed const & rhs ) const { return (int)this->getRawBits() == (int)rhs.getRawBits(); }
bool	Fixed::operator!=( Fixed const & rhs ) const { return !(*this == rhs); }

bool	Fixed::operator< ( Fixed const & rhs ) const { return *this!=rhs && min(*this, rhs) == *this; }
bool	Fixed::operator> ( Fixed const & rhs ) const { return rhs < *this; }
bool	Fixed::operator<=( Fixed const & rhs ) const { return !(*this > rhs); }
bool	Fixed::operator>=( Fixed const & rhs ) const { return !(*this < rhs); }

Fixed 	Fixed::operator+( Fixed const & rhs ) const	{ return this->toFloat() + rhs.toFloat(); }
Fixed 	Fixed::operator-( Fixed const & rhs ) const	{ return this->toFloat() - rhs.toFloat(); }
Fixed 	Fixed::operator*( Fixed const & rhs ) const	{ return this->toFloat() * rhs.toFloat(); }
Fixed 	Fixed::operator/( Fixed const & rhs ) const	{
	if (rhs.getRawBits() == 0)
		return 0;
	return this->toFloat() / rhs.toFloat();
}

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
		this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed &	Fixed::operator++( void ) 	{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed 	Fixed::operator++( int ) {
	Fixed	tmp(*this);
	Fixed::operator++();
	return tmp;
}

Fixed &	Fixed::operator--( void ) 	{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed 	Fixed::operator--( int ) {
	Fixed	tmp(*this);
	Fixed::operator--();
	return tmp;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float			Fixed::toFloat( void ) const	{ return((float)this->getRawBits() / (1<<Fixed::_nbFractionalBits)); }
int				Fixed::toInt( void ) const		{ return((int)roundf(this->toFloat()));	}

Fixed &			Fixed::min(Fixed & a, Fixed & b) 				{ return (a.getRawBits() < b.getRawBits()) ? a : b; }
Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)	{ return (a.getRawBits() < b.getRawBits()) ? a : b; }
Fixed &			Fixed::max(Fixed & a, Fixed & b)				{ return (a.getRawBits() > b.getRawBits()) ? a : b; }
Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)	{ return (a.getRawBits() > b.getRawBits()) ? a : b; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int				Fixed::getRawBits( void ) const		{ return (this->_value); }
void			Fixed::setRawBits( int const raw )	{	this->_value = raw; }

/*
**	---------- PRINTER ---------------------
*/

void					Fixed::printToBinary( float const src) const {

	char				c;
	std::stringstream	output;
	int		tmp_src = *(int *)&src;

	output << "Float  	 = ";
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

	output << "Int    	 = ";

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

	output << "Fixed    = ";
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
