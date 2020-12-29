#include <iostream>
#include <fstream>

void	readFromStdin( void )
{
	std::string		input;
	while (std::getline(std::cin, input))
		std::cout << input.c_str() << std::endl;
}

int		readFromFile(char *filePath)
{
	std::ifstream	ifs(filePath);
	char			c;

	if (ifs.good() == false)
	{
		std::cerr << "Could not open the file passed as argument." << std::endl;
		return (1);
	}
	while (ifs.good() == true)
	{
		ifs.read(&c, 1);
		if (ifs.eof() == true)
			break ;
		std::cout << c;
	}
	ifs.close();
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	if (ac == 1)
		readFromStdin();
	else
		return (readFromFile(av[1]));
	return (0);
}
