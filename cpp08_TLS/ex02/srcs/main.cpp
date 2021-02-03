# include "MutantStack.hpp"
# include "MutantStack.cpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

# include <list>

int main( void ) 	{

	std::cout << RED_COLOR << "~~~~~~~~~~~MAIN FROM SUBJECT~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(42);
		mstack.push(99);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		std::cout << "it after ++ -> " << *it << std::endl;
		--it;
		std::cout << "it after -- -> " << *it << std::endl;

		while (it != ite) {
			std::cout << "while -> " << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);

	}
	std::cout << RED_COLOR << "~~~~~~~~~~END MAIN FROM SUBJECT~~~~~~~~" << RESET_COLOR << std::endl << std::endl;

	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~   SAME WITH A LIST  ~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(42);
		mstack.push_back(99);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		std::cout << "it after ++ -> " << *it << std::endl;
		--it;
		std::cout << "it after -- -> " << *it << std::endl;

		while (it != ite) {
			std::cout << "while -> " << *it << std::endl;
			++it;
		}

		std::list<int> s(mstack);
	}
	std::cout << std::endl << RED_COLOR << "~~~~~~~~~~   operator= overload  ~~~~~~~~" << RESET_COLOR << std::endl;
	{
		MutantStack<int> mstack0;
		MutantStack<int> mstack1;

		mstack0.push(5);
		mstack0.push(17);
		mstack0.push(42);
		std::cout << "top of mstack0 -> " << mstack0.top() << " @ " << &(mstack0.top()) << std::endl;

		std::cout << std::endl << RED_COLOR << "mstack1 = mstack0" << RESET_COLOR << std::endl;
		mstack1 = mstack0;

		std::cout << "top of mstack0 -> " << mstack0.top() << " @ " << &(mstack0.top()) << std::endl;
		std::cout << "top of mstack1 -> " << mstack1.top() << " @ " << &(mstack1.top()) << std::endl;
	}
	return 0;
}
