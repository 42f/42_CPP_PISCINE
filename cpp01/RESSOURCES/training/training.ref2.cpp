#include <iostream>
#include <string>

void	byPtr(std::string *str)
{
	*str += " toi!";
}

void	byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}

void	byRef(std::string &str)
{
	str += " me ?";
}

void	byConstRef(std::string const &str)
{
	std::cout << str << std::endl;
}

int main()	{
	std::string	str = "coucou";

	byPtr(&str);
	byConstPtr(&str);

	str = "Who ?";
	byRef(str);
	byConstRef(str);
};

