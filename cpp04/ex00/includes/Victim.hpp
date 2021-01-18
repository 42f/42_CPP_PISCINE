#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <sstream>
# include <string>

class Victim
{

	public:

		Victim( std::string const name );
		Victim &		operator=( Victim const & rhs );
		virtual ~Victim();

		void					sayHello( void ) const;
		virtual std::string		introduce( void ) const;
		virtual void			getPolymorphed( void ) const;

	protected:
		Victim();
		Victim( Victim const & src );

		std::string		getName( void ) const;

		std::string		_name;

		virtual void			beBorn( void ) const;
		virtual void			beDead( void ) const;

	private:
};

std::ostream &			operator<<( std::ostream & o, Victim const & i );

#endif /* ******************************************************** Victim_H */
