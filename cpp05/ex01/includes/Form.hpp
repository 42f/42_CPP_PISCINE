#ifndef Form_HPP
# define Form_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form( std::string const name, int signGrade, int execGrade );
		~Form( void );

		std::string			getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		bool				getSignStatus( void ) const;

		void				beSigned( Bureaucrat & );

	private:
		Form &		operator=( Form const & rhs );
		Form( Form const & src );

		std::string const	_name;
		bool				_signedStatus;
		int const			_signGrade;
		int const			_execGrade;

};

//std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* *****BVALETTE****** Form_H */
