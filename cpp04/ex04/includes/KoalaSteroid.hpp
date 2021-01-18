#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"
# include <iostream>
# include <string>

class KoalaSteroid : public IAsteroid
{

	public:

		KoalaSteroid( void );
		~KoalaSteroid( void );

		virtual std::string beMined(StripMiner *src) const;
		virtual std::string beMined(DeepCoreMiner *src) const;
		virtual std::string getName() const;


	private:
		KoalaSteroid &		operator=( KoalaSteroid const & rhs );
		KoalaSteroid( IAsteroid const & src );

		static std::string const		_name;

};

//std::ostream &			operator<<( std::ostream & o, KoalaSteroid const & i );

#endif /* *****BVALETTE****** KOALASTEROID_H */
