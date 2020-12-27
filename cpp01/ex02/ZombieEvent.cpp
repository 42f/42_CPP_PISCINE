#include "ZombieEvent.hpp"
#include <stdlib.h>
#include <sys/time.h>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void			ZombieEvent::randomChump( void )	{
	Zombie		*babyZombie;
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
	ZombieEvent::setZombieType(tmp_str);
	srand(tv.tv_usec + 42);
	tmp_str = namesList[rand() % 24];
	babyZombie = ZombieEvent::newZombie(tmp_str);
	babyZombie->announce();
	delete babyZombie;
}

void			ZombieEvent::setZombieType(std::string const type)	{
	ZombieEvent::_storedType = type;
}

Zombie			*ZombieEvent::newZombie(std::string const name)	{
	Zombie		*babyZombie = new Zombie(name);

	babyZombie->setType(ZombieEvent::_storedType);
	return (babyZombie);
}

std::string	ZombieEvent::_storedType = "default_zombie";
/* ************************************************************************** */
