#include <iostream>
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

int main(void) {
	Sample1 instance_0( 'a', 42, 42.21 );
	Sample2 instance_1( 'z', 21, 1337.42 );

	instance_0.a1 = instance_1.a1;
	instance_1.a1 = 'b';

	return (0);
}
