#include <iostream>




int main()	{
	int		nb = 42;

	int		*nbptr = &nb;
	int		&nbref = nb;

	std::cout << "int	" << nb << std::endl;
	std::cout << "int pt	" << *nbptr << std::endl;
	std::cout << "int re	" << nbref << std::endl;

	*nbptr = 21;
	std::cout << "int	" << nb << std::endl;
	std::cout << "int pt	" << *nbptr << std::endl;
	std::cout << "int re	" << nbref << std::endl;

	nbref = 12;
	std::cout << "int	" << nb << std::endl;
	std::cout << "int pt	" << *nbptr << std::endl;
	std::cout << "int re	" << nbref << std::endl;
};
