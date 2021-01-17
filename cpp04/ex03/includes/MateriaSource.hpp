#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource &		operator=( MateriaSource const & rhs );
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		virtual void 		learnMateria(AMateria* newMateria);
		virtual AMateria*	createMateria(std::string const & type);

	private:

		static size_t const	_srcSize = 4;
		AMateria *			_materiaSource[MateriaSource::_srcSize];
};

#endif /* ************************************************************ MATERIASOURCE_H */
