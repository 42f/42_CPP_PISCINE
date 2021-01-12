#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		// Animal( Animal const & src );
		~Animal();

		// Animal &		operator=( Animal const & rhs );

		void	run(int dist);
		void	call(std::string const call) const ;
		void	walk(int dist);

	private:

		int		_numberOfLegs;

};

class Cat : public Animal
{

	public:

	Cat();
	// Cat( Cat const &src );
	~Cat();

	Cat	&		operator=( Cat const & rhs );

	void		scornSomeone(std::string const & target);

	private:

};

class Pony : public Animal
{

	public:

	Pony();
	// Pony( Cat const &src );
	~Pony();

	Pony	&		operator=( Pony const & rhs );

	void		doMagic(std::string const & target);
	void		run(int distance);

	private:

};

// std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */
