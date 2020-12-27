#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <stdlib.h>
#include <sys/time.h>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ZombieHorde::ZombieHorde( int const n )
{
	ZombieHorde::_horde = new Zombie[n];
	for (int i = 0; i < n; i++)
		ZombieHorde::zombieRandomizer(&(ZombieHorde::_horde[i]));
	for (int i = 0; i < n; i++)
		ZombieHorde::_horde[i].announce();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ZombieHorde::~ZombieHorde()	{
	delete [] ZombieHorde::_horde;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ZombieHorde::zombieRandomizer( Zombie *zombieToRandomize )
{
	std::string	typesList[19] = { "Walker", "Ripper", "Deadhead",
	"Growler", "Lame-Brain", "Stinker", "Floater", "Hisser", "Passed_away",
	"Wasted", "Cold_Bodie", "Geek", "Lurker", "Emptie", "Biter", "Creeper",
	"Roamer", "Infected", "Rotter" };
	std::string	namesList[24] = { "Haruto", "Yuto", "Sota", "Yuki", "Hayato",
	"Haruki", "Ryusei", "Koki", "Sora", "Sosuke", "Riku", "Soma", "Ryota",
	"Rui", "Kaito", "Haru", "Kota", "Yusei", "Yuito", "Yuma", "Ren", "Takumi",
	"Minato", "Eita"};
	std::string	tmp_str;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	tmp_str = typesList[rand() % 19];
	zombieToRandomize->setType(tmp_str);

	srand(tv.tv_usec + 42);
	tmp_str = namesList[rand() % 24];
	zombieToRandomize->setName(tmp_str);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
