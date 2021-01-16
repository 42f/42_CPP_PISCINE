#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

class Character
{

	public:

		Character();
		~Character();



	private:
		Character &		operator=( Character const & rhs );
		Character( Character const & src );



};

//std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ************************************************************ CHARACTER_H */
