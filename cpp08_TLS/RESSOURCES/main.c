#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

# define OUT false
# define IN true

int main ( int ac, char **av)	{

	if (ac != 2)
		return 1;
	char	c = ' ';
	size_t	len = strlen(av[1]);
	if (len == 0)
		return 0;
	size_t	i = 0;
	size_t	count = 0;
	bool	state = IN;
	while (i < len)
	{

		if (av[1][i] == c && state == OUT)
			state = IN;
		if (av[1][i] != c && state == IN)
		{
			count++;
			state = OUT;
		}
		i++;
	}
	return ((int)count);
}
