#ifndef IASTEROID_HPP
# define IASTEROID_HPP

# include <iostream>
# include <string>

class StripMiner;
class DeepCoreMiner;

class IAsteroid
{

	public:

		virtual ~IAsteroid() {}
		// virtual std::string beMined(IMiningLaser *src) const = 0;
		virtual std::string beMined(StripMiner *src) const = 0;
		virtual std::string beMined(DeepCoreMiner *src) const = 0;
		virtual std::string getName() const = 0;
};

#endif /* *****BVALETTE****** IASTEROID_H */
