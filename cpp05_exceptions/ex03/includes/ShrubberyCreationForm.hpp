#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm( std::string const &target );
		~ShrubberyCreationForm( void );

		void		execute( Bureaucrat const &) const;

	private:
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );

		void			action( void ) const;
		std::string		_target;

};

//std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* *****BVALETTE****** SHRUBBERYCREATIONFORM_H */
