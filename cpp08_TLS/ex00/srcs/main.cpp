# include <iostream>
# include <list>
# include <deque>
# include <algorithm>
# include "easyfind.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	{
		std::cout << std::endl << RED_COLOR << "[ list of int ]" << RESET_COLOR << std::endl;
		std::list<int>	lst;

		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(34);
		lst.push_back(49);
		lst.push_back(19);

		try {
			int	const target = 19;
			std::cout << "Trying to find " << target << std::endl;
			std::list<int>::const_iterator output = easyfind(lst, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
		try {
			int	target = 1000;
			std::cout << "Trying to find " << target << std::endl;
			std::list<int>::const_iterator output = easyfind(lst, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
	}
	{
		std::cout << std::endl << RED_COLOR << "[ deque of int ]" << RESET_COLOR << std::endl;
		int myints[] = {16,2,77,42,19,29};
 		std::deque<int> myDeque (myints, myints + sizeof(myints) / sizeof(int) );

		try {
			int	const target = 19;
			std::cout << "Trying to find " << target << std::endl;
			std::deque<int>::const_iterator output = easyfind(myDeque, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
		try {
			int	target = 1000;
			std::cout << "Trying to find " << target << std::endl;
			std::deque<int>::const_iterator output = easyfind(myDeque, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
	}
	{
		std::cout << std::endl << RED_COLOR << "[ list of 10000000 int (of value 42 except last one: value 19) ]" << RESET_COLOR << std::endl;

 		std::list<int> myInts (10000000, 42);
		std::list<int>::iterator	it = myInts.end();
		it--;
		it--;
		*it = 19;
		std::cout << "it -> " << *it << std::endl;

		try {
			int	const target = 19;
			std::cout << "Trying to find " << target << std::endl;
			std::list<int>::const_iterator output = easyfind(myInts, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
		try {
			int	target = 1000;
			std::cout << "Trying to find " << target << std::endl;
			std::list<int>::const_iterator output = easyfind(myInts, target);
			std::cout << "FOUND -> " << *output << " @ " << &(*output) << std::endl;
		}
		catch (const std::exception &e)	{
			std::cout << "Got exception, can not be found." << std::endl;
		}
	}
	return 0;
}
