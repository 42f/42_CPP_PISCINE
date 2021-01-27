#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm( std::string const &target );
		~RobotomyRequestForm( void );

		void		execute( Bureaucrat const &) const ;

	private:
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		RobotomyRequestForm( RobotomyRequestForm const & src );

		void			action( void ) const;
		std::string		_target;
		mutable bool	_failureSwitch;				// permet de conserver les methodes de AForm en const.

};

//std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* *****BVALETTE****** ROBOTOMYREQUESTFORM_H */
