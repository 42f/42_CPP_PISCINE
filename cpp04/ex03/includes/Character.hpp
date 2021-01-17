#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class Character : public ICharacter
{

	public:

		Character( std::string name );
		Character &		operator=( Character const & rhs );
		Character( Character const & src );
		~Character();

		virtual std::string const & 	getName() const;
		virtual void 					equip(AMateria* m);
		virtual void 					unequip(int idx);
		virtual void 					use(int idx, ICharacter& target) ;

	private:

		static size_t const	_inventorySize = 4;
		AMateria *			_inventory[Character::_inventorySize];
		std::string const	_name;
};

//std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ************************************************************ CHARACTER_H */
