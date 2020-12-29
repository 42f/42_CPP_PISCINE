#include <iostream>
#include <string>

class Student
{

	private :
		std::string _login;


	public :
		Student(std::string const & login) : _login(login) {
		}

		std::string&	getLoginRef() {
			return this->_login;
		}

		std::string const &	getLoginRefConst() const {
			return this->_login;
		}

		std::string *	getLoginPtr() {
			return &(this->_login);
		}

		std::string const *	getLoginPtrConst() const {
			return &(this->_login);
		}

};


int main() {

	Student			bob = Student("boby");
	Student	const	jim = Student("jimy");

	std::cout << bob.getLoginRefConst() << std::endl;
	std::cout << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << std::endl;
	std::cout << *(jim.getLoginPtrConst()) << std::endl;
	std::cout << "       " << std::endl;

	bob.getLoginRef() = "marcel";

	std::cout << bob.getLoginRefConst() << std::endl;
	std::cout << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << std::endl;
	std::cout << *(jim.getLoginPtrConst()) << std::endl;
	std::cout << "       " << std::endl;

};
