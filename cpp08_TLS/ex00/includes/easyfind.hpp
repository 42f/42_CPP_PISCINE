#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template< typename T>
typename T::const_iterator	easyfind(T const &src, int const target)	{

	typename T::const_iterator		it = src.begin();
	typename T::const_iterator		itEnd = src.end();

	it = std::find(it, itEnd, target);
	if (it != itEnd )
		return (it);
	else
		throw std::exception();
}

#endif /* *****BVALETTE****** EASYFIND_H */
