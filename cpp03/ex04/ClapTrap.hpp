#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap( std::string const name );
		ClapTrap( std::string const name, ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);

		std::string const	getName( void ) const;

	protected:

		void				setLevel( unsigned int );
		void				setEnergyPoints( unsigned int );
		void				setHitPoints( unsigned int );
		void		 		setMaxEnergyPoints( unsigned int );
		void		 		setMaxHitPoints( unsigned int );
		void		 		setMeleeAttackDamage( unsigned int );
		void		 		setRangedAttackDamage( unsigned int );
		void		 		setArmorDamageReduction( unsigned int );

		unsigned int		getLevel( void ) const;
		unsigned int		getEnergyPoints( void ) const;
		unsigned int		getHitPoints( void ) const;
		unsigned int 		getMaxEnergyPoints( void ) const;
		unsigned int 		getMaxHitPoints( void ) const;
		unsigned int 		getMeleeAttackDamage( void ) const;
		unsigned int 		getRangedAttackDamage( void ) const;
		unsigned int 		getArmorDamageReduction( void ) const;

		std::string	 const	_name;

	private:
		unsigned int		_level;
		unsigned int		_energyPoints;
		unsigned int		_hitPoints;
		unsigned int 		_maxEnergyPoints;
		unsigned int 		_maxHitPoints;
		unsigned int 		_meleeAttackDamage;
		unsigned int 		_rangedAttackDamage;
		unsigned int 		_armorDamageReduction;

};

std::ostream &		operator<<( std::ostream & o, ClapTrap const & i);

#endif /* ******************************************************** ClapTrap_H */
