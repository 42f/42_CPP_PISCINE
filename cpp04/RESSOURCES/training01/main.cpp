#include <iostream>

class Base {
 public:
	Base() {
		s = new std::string [128];
	}
     ~Base() {
		delete [] s;
		std::cout << "base destructor" << std::endl;/* releases Base's resources */ }

	public:
		std::string *s;
};

class Derived : public Base {
    ~Derived() {
		std::cout << "derived dest" << std::endl; /* releases Derived's resources */ }
};

int main()
{
    Base* b = new Derived;
    delete b; // Makes a virtual function call to Base::~Base()
              // since it is virtual, it calls Derived::~Derived() which can
              // release resources of the derived class, and then calls
              // Base::~Base() following the usual order of destruction
}
