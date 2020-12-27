#include "Pony.hpp"
#include <stdlib.h>

Pony *ponyOnTheHeap(std::string const & name )
{
	Pony	*newPony = new Pony(name);

	std::cout	<< "-----------NEW PONY" << std::endl
				<< "Name: " <<newPony->getName() << std::endl
				<< "Color: " <<  newPony->getColor() << std::endl
				<< "Special talent: " <<  newPony->getSpecialPower() << std::endl
				<< "-----------" << std::endl;
	return (newPony);
}

Pony ponyOnTheStack(std::string const & name )
{
	Pony	newPony = Pony(name);

	std::cout	<< "-----------NEW PONY" << std::endl
				<< "Name: " <<newPony.getName() << std::endl
				<< "Color: " <<  newPony.getColor() << std::endl
				<< "Special talent: " <<  newPony.getSpecialPower() << std::endl
				<< "-----------" << std::endl;
	return (newPony);
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Pony::Pony( std::string const & name) : _name(name)	{
	std::string colour[4] = { "Blue", "Red",
                              "Orange", "Yellow" };
	std::string specialPower[4] = { "Poop Rainbow on the Wall", "Pee symphony on the Floor",
                              "Fart National Anthem, with bells", "Eat the World Peace" };
	int			random;

	srand(time(0) + name.at(0));
	random = (rand() % 4);
	this->_color = colour[random];
	srand(time(0) - name.at(0));
	random = (rand() % 4);
	this->_specialPower = specialPower[random];
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Pony::~Pony()
{
	std::cout << this->_name << " has died" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Pony::getName( void ) const {
	return (this->_name);
}

std::string Pony::getColor( void ) const {
	return (this->_color);
}

std::string Pony::getSpecialPower( void ) const {
	return (this->_specialPower);
}


/* ************************************************************************** */
