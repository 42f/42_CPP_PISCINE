#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <iterator>

#include <algorithm>
#include <numeric>

template< typename T>
class MutantStack : public std::stack< T, std::list<T> >
{

	public:

		class iterator : public MutantStack
		{

			public:
				typedef	std::forward_iterator_tag	iterator_categor;
				typedef	std::ptrdiff_t				difference_type;
				typedef	T 							value_type;
				typedef	T* 							pointer;
				typedef	T& 							reference;

				iterator(pointer ptr) : _ptr(ptr)	{

					std::cout << "IT    Instanciate with : " << this->_ptr << std::endl;
					std::cout << "IT    Instanciate @    : " << this << std::endl;
				}


				reference	operator*() const	{ return *_ptr; }
				pointer 	operator->()		{ return _ptr; }

				// Prefix increment
				iterator&	operator++() {


					// size_t size = this->size() - 1;
					// std::stack< T, std::list<T> >	tmpStack;
					// for (size_t i = 0; i < size; i++)
					// {
					// 	tmpStack.push(this->top());
					// 	this->pop();
					// }
					// iterator	end = &(this->top());
					// for (size_t i = 0; i < size; i++)
					// {
					// 	this->push(tmpStack.top());
					// 	tmpStack.pop();
					// }
					// return end;


					// size_t size = this->size() - 1;
					// std::stack< T, std::list<T> >	tmpStack;

					// size_t	i = 0;
					// iterator b = this->begin();
					std::cout << "--------->  " << this->_ptr << std::endl;
					std::cout << "--------->  " << MutantStack::top() << std::endl;
					// while (i < size)
					// {
						// if (this->top() == *_ptr)
						// 	break ;
					// 	tmpStack.push(this->top());
					// 	this->pop();
					// 	i++;
					// }

					// this->push(tmpStack.top());
					// tmpStack.pop();
					// _ptr = &(this->top());
					iterator & 	newIt = *this;

					// i++;
					// i = 0;
					// while (i < size)
					// {
					// 	this->push(tmpStack.top());
					// 	tmpStack.pop();
					// 	i++;
					// }
					return newIt;





					// _ptr++;

					// std::cout << "pre inc: address " << _ptr << "\t value " << *_ptr << std::endl;
					// return *this;
				}

				// Postfix increment
				iterator	operator++(int)		{ iterator tmp = *this; ++(*this); return tmp; }

				int		getPos( void )	const {	return this->_pos;	}

			private:
				pointer	_ptr;
				int		_pos;
		};

		iterator end() { return iterator(&this->top()); }
		iterator begin() {

			size_t size = this->size() - 1;
			std::stack< T, std::list<T> >	tmpStack;
			for (size_t i = 0; i < size; i++)
			{
				tmpStack.push(this->top());
				this->pop();
			}
			iterator	end = &(this->top());
			for (size_t i = 0; i < size; i++)
			{
				this->push(tmpStack.top());
				tmpStack.pop();
			}
			return end;
		}

		MutantStack( void )	{

			std::cout << "STACK Instanciate @    : " << this << std::endl;
		};
		~MutantStack( void ){};

	private:
		MutantStack &		operator=( MutantStack const & rhs );
		MutantStack( MutantStack const & src );
};


// std::ostream &			operator<<( std::ostream & o, MutantStack const & i );

#endif /* *****BVALETTE****** MUTANTSTACK_H */
