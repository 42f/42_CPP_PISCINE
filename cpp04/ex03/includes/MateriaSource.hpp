#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

class MateriaSource
{

	public:

		MateriaSource();
		~MateriaSource();



	private:
		MateriaSource &		operator=( MateriaSource const & rhs );
		MateriaSource( MateriaSource const & src );



};

//std::ostream &			operator<<( std::ostream & o, MateriaSource const & i );

#endif /* ************************************************************ MATERIASOURCE_H */
