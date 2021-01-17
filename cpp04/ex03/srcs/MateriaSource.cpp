# include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < MateriaSource::_srcSize; i++)	{
		this->_materiaSource[i] = NULL;
	}
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MateriaSource::_srcSize; i++)
		if (this->_materiaSource[i] != NULL)
			delete this->_materiaSource[i];
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (size_t i = 0; i < MateriaSource::_srcSize; i++)
		{
			if (rhs._materiaSource[i] != NULL)
				this->_materiaSource[i] = rhs._materiaSource[i]->clone();
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void 		MateriaSource::learnMateria(AMateria* newMateria)	{

	if (newMateria != NULL)
	{
		for (size_t i = 0; i < MateriaSource::_srcSize; i++)
		{
			if (this->_materiaSource[i] == NULL)
			{
				this->_materiaSource[i] = newMateria->clone();
				break ;
			}
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)	{

	for (size_t i = 0; i < MateriaSource::_srcSize; i++)
	{
		if (this->_materiaSource[i] != NULL && this->_materiaSource[i]->getType().compare(type) == 0)
			return (this->_materiaSource[i]->clone());
	}
	return (NULL);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
