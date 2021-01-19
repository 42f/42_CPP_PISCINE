#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm( std::string const &target );
		~PresidentialPardonForm( void );

		void		execute( Bureaucrat const &) const;

	private:
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		PresidentialPardonForm( PresidentialPardonForm const & src );

		void			action( void ) const;
		std::string		_target;

};

//std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* *****BVALETTE****** PRESIDENTIALPARDONFORM_H */
