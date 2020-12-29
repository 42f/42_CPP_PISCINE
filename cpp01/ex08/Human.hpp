#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>

class Human	{

	private:

		void	meleeAttack(std::string const &target) const ;
		void	rangedAttack(std::string const &target) const ;
		void	intimidatingShout(std::string const &target) const ;
		void	nothingAttack(__attribute__((unused))std::string const &target) const ;

	public:

		void	action(std::string const &action_name, std::string const &target);
		Human();
		~Human();
};

#endif /* *********************************************************** HUMAN_H */
