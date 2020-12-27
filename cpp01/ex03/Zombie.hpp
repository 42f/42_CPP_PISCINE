#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		void	announce() const ;
		void	setType(std::string const type);
		void	setName(std::string const name);

		Zombie();
		~Zombie();

	private:

		std::string		_name;
		std::string		_type;

};

#endif /* ********************************************************** ZOMBIE_H */
