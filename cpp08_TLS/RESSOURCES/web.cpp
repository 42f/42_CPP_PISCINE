// Sample custom iterator.
// By perfectly.insane (http://www.dreamincode.net/forums/index.php?showuser=76558)
// From: http://www.dreamincode.net/forums/index.php?showtopic=58468

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template <typename T>
class fixed_array
{
    public:

        typedef int size_type;

        class iterator
        {
            public:
                typedef iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                reference operator*() { return *ptr_; }
                pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };

        class const_iterator
        {
            public:
                typedef const_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                const reference operator*() { return *ptr_; }
                const pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };


        fixed_array(size_type size) : size_(size) {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }

        T& operator[](size_type index)
        {
            assert(index < size_);
            return data_[index];
        }

        const T& operator[](size_type index) const
        {
            assert(index < size_);
            return data_[index];
        }

        iterator begin()
        {
            return iterator(data_);
        }

        iterator end()
        {
            return iterator(data_ + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(data_);
        }

        const_iterator end() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        T* data_;
        size_type size_;
};


int main()
{
    fixed_array<double> point3d(3);
    point3d[0] = 2.3;
    point3d[1] = 3.2;
    point3d[2] = 4.2;

    for(fixed_array<double>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    std::vector<double> vec;
    std::copy(point3d.begin(), point3d.end(), std::back_inserter(vec));

    for(std::vector<double>::iterator i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}












/***********************************************************/







//: C16:NestedIterator.cpp
// Nesting an iterator inside the container
//{L} fibonacci
#include "fibonacci.h"
#include "../require.h"
#include <iostream>
#include <string>
using namespace std;

class IntStack {
  enum { ssize = 100 };
  int stack[ssize];
  int top;

    public:
        IntStack() : top(0) {}
        void push(int i) {
            require(top < ssize, "Too many push()es");
            stack[top++] = i;
        }
        int pop() {
            require(top > 0, "Too many pop()s");
            return stack[--top];
        }


        class iterator;
        friend class iterator;

        class iterator {

            private:
                IntStack&   s;
                int         index;

            public:
                iterator(IntStack& is) : s(is), index(0) {}

                // To create the "end sentinel" iterator:
                iterator(IntStack& is, bool) : s(is), index(s.top) {}

                int current() const { return s.stack[index]; }

                int operator++() { // Prefix
                require(index < s.top,
                    "iterator moved out of range");
                return s.stack[++index];
                }

                int operator++(int) { // Postfix
                require(index < s.top,
                    "iterator moved out of range");
                return s.stack[index++];
                }

                // Jump an iterator forward
                iterator& operator+=(int amount) {
                require(index + amount < s.top,
                    "IntStack::iterator::operator+=() "
                    "tried to move out of bounds");
                index += amount;
                return *this;
                }

                // To see if you're at the end:
                bool operator==(const iterator& rv) const {
                    return index == rv.index;
                }
                bool operator!=(const iterator& rv) const {
                    return index != rv.index;
                }

                friend ostream&
                operator<<(ostream& os, const iterator& it) {
                    return os << it.current();
                }
        };
    iterator begin() { return iterator(*this); }

    // Create the "end sentinel":
    iterator end() { return iterator(*this, true);}
};








int main() {
  IntStack is;
  for(int i = 0; i < 20; i++)
    is.push(fibonacci(i));
  cout << "Traverse the whole IntStack\n";
  IntStack::iterator it = is.begin();
  while(it != is.end())
    cout << it++ << endl;
  cout << "Traverse a portion of the IntStack\n";
  IntStack::iterator
    start = is.begin(), end = is.begin();
  start += 5, end += 15;
  cout << "start = " << start << endl;
  cout << "end = " << end << endl;
  while(start != end)
    cout << start++ << endl;
} ///:~








# include "web.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

web::web( void )	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
web::web( const web & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

web::~web()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
web &				web::operator=( web const & rhs )	{

    if ( this != &rhs )
    {
        this->_value = rhs.getValue();
    }
    return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, web const & i )	{

    o << "Value = " << i.getValue();
    return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
