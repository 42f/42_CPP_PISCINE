#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void		outputToFile(std::string &content, std::ofstream &ofs)
{
	ofs.write(content.c_str(), content.length());
	ofs.close();
}

void		replaceProcess(std::string &content, std::string &s1, std::string &s2)
{
	size_t		pos = 0;
	size_t		len_s1 = s1.length();

	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, len_s1);
		content.insert(pos, s2);
	}
}

std::string	extractFile(std::ifstream &ifs)
{
	ifs.seekg(0, std::ios::end);
	size_t	len = ifs.tellg();
	ifs.seekg(0);
	std::string	content(len + 1, '\0');
	ifs.read(&content[0], len);
	ifs.close();
	return (content);
}

int			main( int const ac, char const **av )
{
	if (ac == 4)
	{
		std::string		filePath(av[1]);
		std::string		s1(av[2]);
		std::string		s2(av[3]);
		if (filePath.empty() == false && s1.empty() == false && s2.empty() == false)
		{
			std::ifstream	ifs(filePath.c_str());
			if (ifs == NULL)
			{
				std::cout << "Invalid input file" << std::endl;
				return (1);
			}
			std::string		content = extractFile(ifs);
			replaceProcess(content, s1, s2);
			filePath.append(".replace");
			std::ofstream	ofs(filePath.c_str(), std::ofstream::trunc);
			if (ofs == NULL)
			{
				std::cout << "Could not open the output file" << std::endl;
				return (1);
			}
			outputToFile(content, ofs);
		}
		else
		{
			std::cout << "Invalid arguments." << std::endl;
			return (1);
		}
	}
	else
		std::cout << "Replace takes exactly 3 arguments made up of non empty strings" << std::endl;
	return (0);
}
