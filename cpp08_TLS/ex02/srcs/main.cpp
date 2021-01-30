# include "MutantStack.hpp"
// # include "MutantStack.cpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

# include <limits>
# include <stdlib.h>
# include <algorithm>

int main( void ) 	{

	std::cout << RED_COLOR << "~~~~~~~~~~~MAIN FROM SUBJECT~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{

		// MutantStack<int> mstack;
		// mstack.push(5);
		// mstack.push(17);

		// std::cout << mstack.top() << std::endl;

		// mstack.pop();

		// std::cout << mstack.size() << std::endl;

		// mstack.push(3);
		// mstack.push(5);
		// mstack.push(737);

		// //[...] mstack.push(0);

		// MutantStack<int>::iterator it = mstack.begin();
		// MutantStack<int>::iterator ite = mstack.end();

		// ++it;
		// --it;

		// while (it != ite) {
		// 	std::cout << *it << std::endl;
		// 	++it;
		// }

		// std::stack<int> s(mstack);

	}
	std::cout << RED_COLOR << "~~~~~~~~~~END MAIN FROM SUBJECT~~~~~~~~" << RESET_COLOR << std::endl << std::endl;

	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~    MAIN BVALETTE #1  ~~~~~~~~" << RESET_COLOR << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(33);
		mstack.push(42);
		std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;

{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "Value at it  -> " << it.current() << std::endl;
		std::cout << "Value at ite -> " << ite.current() << std::endl;
}
		mstack.push(21);
		std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;
{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "Value at it  -> " << it.current() << std::endl;
		std::cout << "Value at ite -> " << ite.current() << std::endl;
}
	}





		// std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;
		// mstack.push(17);
		// std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;
		// mstack.push(17);
		// std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;
		// mstack.push(17);
		// std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;
		// mstack.push(999);
		// std::cout << "added " << mstack.top() << "\t @ " << &(mstack.top()) << std::endl;


		// mstack.pop();

		// std::cout << " SIZE = " << mstack.size() << std::endl;

		// mstack.push(3);
		// mstack.push(5);
		// mstack.push(737);
		// mstack.push(0);

		// std::cout << "top value : " << mstack.top() << std::endl;
		// std::cout << " SIZE = " << mstack.size() << std::endl;

		// MutantStack<int>::iterator it;
		// MutantStack<int>::iterator it = &(mstack.top());

		// std::cout << "----" << std::endl;

		// MutantStack<int>::iterator it = mstack.begin();
		// std::cout << " @ it  " << *it << std::endl;
		// // std::cout << "iterator derefer " << *it << std::endl;
		// std::cout << "----" << std::endl;
		// MutantStack<int>::iterator ite = mstack.end();
		// std::cout << " @ ite " << *ite << std::endl;
		// // std::cout << "iterator derefer " << *ite << std::endl;
		// ++it;
		// // ++ite;
		// std::cout << " @ ite after ++ " << *it << std::endl;
		// // std::cout << "iterator address " << *it << std::endl;
		// --it;

		// while (it != ite) {
		// 	std::cout << *it << std::endl;
		// 	++it;
		// }

		// std::stack<int> s(mstack);
		// std::cout << "(s) top value : " << s.top() << std::endl;
		// std::cout << "(s)  SIZE = " << s.size() << std::endl;
	// }

	return 0;
}
