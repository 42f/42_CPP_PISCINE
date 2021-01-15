#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>


class AWeapon
{
	public:
		AWeapon( std::string const & name, int apcost, int damage );
		virtual ~AWeapon();

		std::string const	getName() const;
		int					getAPCost() const;
		int					getDamage() const;
		virtual void		attack() const = 0;

	private:
		AWeapon( AWeapon const & src );
		AWeapon &			operator=( AWeapon const & src );

	protected:
		std::string const	_name;
		int const			_apcost;
		int const			_damage;
};

#endif /* ********************************************************* AWEAPON_H */
