#include "Squad.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Squad::Squad() : _count(0), _units(NULL)
{
}

// Squad::Squad( const Squad & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Squad::~Squad()
{
	for (int i = 0; i < this->getCount(); i++)
		delete this->_units[i];
	delete [] this->_units;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Squad &				Squad::operator=( Squad const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

int				Squad::getCount( void ) const	{
	return (this->_count);
}

ISpaceMarine*	Squad::getUnit(int unitToFind) const	{
	if (unitToFind >= 0 && unitToFind < this->getCount())
		return (this->_units[unitToFind]);
	else
		return (NULL);

}

int				Squad::push(ISpaceMarine* unitToPush)	{

	if (unitToPush == NULL)
		return (-1);
	for (int i = 0; i < this->getCount(); i++)	{
		if (this->_units[i] == unitToPush)
			return (-1);
	}

	ISpaceMarine** 	tmpUnits = new ISpaceMarine*[this->getCount() + 1];
	for (int i = 0; i < this->getCount(); i++)
		tmpUnits[i] = this->_units[i];

	tmpUnits[this->getCount()] = unitToPush;

	delete [] this->_units;

	this->_units = tmpUnits;
	this->_count++;
	return (this->getCount());
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
