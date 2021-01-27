#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template< typename T>
typename T::const_iterator	easyfind(T const &src, int const target)	{

	typename T::const_iterator		it = src.begin();
	typename T::const_iterator		itEnd = src.end();

	std::cout << "Const function" << std::endl;
	for (; it != itEnd; it++)
	{
		if (*it == target)
			return it;
	}
	throw std::exception();
}

#endif /* *****BVALETTE****** EASYFIND_H */
