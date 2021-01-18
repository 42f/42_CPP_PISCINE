#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"
# include <iostream>
# include <string>

class PlasmaRifle : public AWeapon
{

	public:
		PlasmaRifle();
		virtual ~PlasmaRifle();

		virtual void		attack() const;
	private:
		PlasmaRifle( PlasmaRifle const & src );
		PlasmaRifle &		operator=( PlasmaRifle const & rhs );

};

#endif /* ***************************************************** PlasmaRifle_H */
