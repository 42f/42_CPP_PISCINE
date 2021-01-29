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

		struct iterator
		{
			typedef	std::forward_iterator_tag 	iterator_categor;
		    typedef	std::ptrdiff_t 	difference_type;
		    typedef	T 	value_type;
		    typedef	T* 	pointer;
		    typedef	T& 	reference;

			iterator(pointer ptr) : _ptr(ptr)	{ std::cout << this << std::endl;}

			reference operator*() const { return *_ptr; }
    		pointer operator->() { return _ptr; }

    		// Prefix increment
    		iterator& operator++() { _ptr++; return *this; }

    		// Postfix increment
    		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

			private:
				pointer	_ptr;

		};

		iterator begin() { return iterator(&this->top()); }
		iterator end() {

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
		// iterator end()   { return iterator(&this + this.size()); } // 200 is out of boundsm

		MutantStack( void );
		~MutantStack( void );

	private:
		MutantStack &		operator=( MutantStack const & rhs );
		MutantStack( MutantStack const & src );
};
/**
template< typename T>
class MutantStack : public std::stack<T>
{

	public:

		typedef int size_type;

		class iterator
		{
			public:
				typedef iterator self_type;

				typedef T  	value_type;
				typedef T&	reference;
				typedef T*	pointer;

				typedef 	std::forward_iterator_tag iterator_category;
				typedef 	int difference_type;

                iterator( pointer ptr ) : _ptr(ptr) {};

				// self_type 	operator++() { self_type i = *this; ptr_++; return i; };
				// self_type 	operator++(__attribute__((unused))int junk) { ptr_++; return *this; };

				reference 	operator*() { return *_ptr; };

				pointer 		operator->() { return _ptr; };
				// bool 		operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; };
				// bool 		operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; };

			private:
				pointer _ptr;
		};

		MutantStack( void );
		~MutantStack( void );

		iterator begin()
        {
			std::cout << "val this " << this << std::endl;
            return (this);
        };

		// iterator end()
        // {
        //     return iterator(this + this->size());
        // };

	private:
		MutantStack &		operator=( MutantStack const & rhs );
		MutantStack( MutantStack const & src );
};

// std::ostream &			operator<<( std::ostream & o, MutantStack const & i );
*/
#endif /* *****BVALETTE****** MUTANTSTACK_H */
