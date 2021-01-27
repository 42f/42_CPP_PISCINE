#include <iostream>
#include "Sample.class.hpp"

int main(void) {
	Sample inst(42, 72, 125);

	inst.getBar();
	inst.setBar(11, 111, 1111);
	inst.getBar();
	return (0);
}
