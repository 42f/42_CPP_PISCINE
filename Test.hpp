#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>

class Test
{

	public:

		Test();
		Test( Test const & src );
		~Test();

		Test &		operator=( Test const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Test const & i );

#endif /* ************************************************************ TEST_H */