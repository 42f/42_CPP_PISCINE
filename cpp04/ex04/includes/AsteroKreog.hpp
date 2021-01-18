#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include "IAsteroid.hpp"
# include <iostream>
# include <string>

class AsteroKreog : public IAsteroid
{

	public:

		AsteroKreog( void );
		~AsteroKreog( void );

		virtual std::string beMined(StripMiner *src) const;
		virtual std::string beMined(DeepCoreMiner *src) const;
		virtual std::string getName() const;


	private:
		AsteroKreog &		operator=( AsteroKreog const & rhs );
		AsteroKreog( IAsteroid const & src );

		static std::string const		_name;

};

//std::ostream &			operator<<( std::ostream & o, AsteroKreog const & i );

#endif /* *****BVALETTE****** ASTEROKREOG_H */
