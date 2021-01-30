
# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <iterator>

#include <algorithm>
#include <numeric>


template< typename T>
class test : public std::stack< T, std::list<T> >
{
	public:
	class nested : public test	{
		public:
		nested( void )	{ this->X = test::X; };
		void get( void ) { std::cout << this->X << std::endl; }
	};

	void set( int i )	{ this->X = i; };

	private:
		int X;
};

int main( void )	{

	test<int> a;
	test<int> b;

	std::cout << "empty top : " << &a.top() << std::endl;

	a.set(42);
	test<int>::nested	c;
	c.get();
	return 0;

	a.push(11);
	std::cout << "address front : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(22);

	std::cout << "address top : " << &a.top() << std::endl;
	a.push(123132);
	std::cout << "address top : " << &a.top() << std::endl;

	size_t size = a.size() - 1;
	std::cout << "top at start " << a.top() << " address: " << &a.top() << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		b.push(a.top());
		a.pop();
	}
	std::cout << "front " << a.top() << " address: " << &a.top() << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		a.push(b.top());
		b.pop();
	}
	std::cout << "top after " << a.top() << " address: " << &a.top() << std::endl;
	std::cout << "sizeof -> " << sizeof(test<int>) << std::endl;

	return(0);
}
