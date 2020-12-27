#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{
	public:

		Pony( std::string const & name );
		~Pony();

		std::string			getName( void ) const;
		std::string			getColor( void ) const;
		std::string 		getSpecialPower( void ) const;

	private:

		std::string	const	_name;
		std::string			_color;
		std::string			_specialPower;
};

Pony	*ponyOnTheHeap(std::string const & name ) ;
Pony	ponyOnTheStack(std::string const & name ) ;

#endif /* ************************************************************ PONY_H */
