#include "Fixed.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_nbFractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value((int)value << Fixed::_nbFractionalBits) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_nbFractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

const int Fixed::_nbFractionalBits = 8;

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << Fixed::_nbFractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->_value >> Fixed::_nbFractionalBits);
}

/* ************************************************************************** */
