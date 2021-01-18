#ifndef SPACEGUN_HPP
# define SPACEGUN_HPP

# include "AWeapon.hpp"
# include <iostream>
# include <string>

class SpaceGun : public AWeapon
{

	public:
		SpaceGun();
		virtual ~SpaceGun();

		virtual void		attack() const;
	private:
		SpaceGun( SpaceGun const & src );
		SpaceGun &		operator=( SpaceGun const & rhs );

};

#endif /* ***************************************************** SpaceGun_H */
