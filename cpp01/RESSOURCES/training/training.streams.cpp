#include <iostream>
#include <fstream>

int main() {
	std::ifstream	marcel;
	std::string		dst1;
	unsigned int	dst2;

	marcel.open("numbers");
	marcel >> dst1 >> dst2;

	std::cout << dst1 << " " << dst2 << std::endl;
	dst1 += " >";
	dst2 += 1;
	std::cout << dst1 << " " << dst2 << std::endl;

	std::ofstream	pilou("file.out");

	pilou << "coucou" << std::endl;
	pilou.close();
};
