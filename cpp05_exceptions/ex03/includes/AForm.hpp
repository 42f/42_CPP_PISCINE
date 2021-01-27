#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{

	public:

		AForm( std::string const name, int signGrade, int execGrade );
		virtual ~AForm( void );

		std::string			getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		bool				getSignStatus( void ) const;

		void				beSigned( Bureaucrat & );

		void				executionCheck( Bureaucrat const & ) const;
		virtual void		execute( Bureaucrat const & ) const = 0;

	private:
		AForm &		operator=( AForm const & rhs );
		AForm( AForm const & src );

		std::string const	_name;
		bool				_signedStatus;
		int const			_signGrade;
		int const			_execGrade;

};

//std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* *****BVALETTE****** AForm_H */
