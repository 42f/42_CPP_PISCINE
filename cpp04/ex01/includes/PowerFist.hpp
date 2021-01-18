#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"
# include <iostream>
# include <string>

class PowerFist : public AWeapon
{

	public:
		PowerFist();
		virtual ~PowerFist();

		virtual void		attack() const;
	private:
		PowerFist( PowerFist const & src );
		PowerFist &		operator=( PowerFist const & rhs );

};

#endif /* ***************************************************** PowerFist_H */
