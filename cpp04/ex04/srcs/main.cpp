
# include "AsteroKreog.hpp"
# include "DeepCoreMiner.hpp"
# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"
# include "KoalaSteroid.hpp"
# include "MiningBarge.hpp"
# include "StripMiner.hpp"

# include <iostream>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	std::cout << std::endl << RED_COLOR << "[ MAIN BVALETTE ]" << RESET_COLOR << std::endl;
	{

		IAsteroid	*astero = new AsteroKreog;
		IAsteroid	*comet = new KoalaSteroid;

		MiningBarge	barge;

		IMiningLaser	*deep = new DeepCoreMiner;
		IMiningLaser	*strip = new StripMiner;

		std::cout << std::endl << RED_COLOR << "[	-- equip barge with deep: slot 1]" << RESET_COLOR << std::endl;
		barge.equip(deep);
		std::cout << std::endl << RED_COLOR << "[	-- equip barge with strip: slot 2]" << RESET_COLOR << std::endl;
		barge.equip(strip);
		std::cout << std::endl << RED_COLOR << "[	-- equip barge with deep: slot 3]" << RESET_COLOR << std::endl;
		barge.equip(deep);
		std::cout << std::endl << RED_COLOR << "[	-- equip barge with deep: slot 4]" << RESET_COLOR << std::endl;
		barge.equip(deep);
		std::cout << std::endl << RED_COLOR << "[	-- equip barge with strip: ( slot 5/4, should not equip)]" << RESET_COLOR << std::endl;
		barge.equip(strip);

		std::cout << std::endl << RED_COLOR << "[	-- mine on astero]" << RESET_COLOR << std::endl;
		barge.mine(astero);
		std::cout << std::endl << RED_COLOR << "[	-- mine on comet]" << RESET_COLOR << std::endl;
		barge.mine(comet);

		delete astero;
		delete comet;
		delete deep;
		delete strip;
	}
	return 0;
}
