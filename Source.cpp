#include "Header.h"

int main(int argc, char** argv)
{
	auto falsePredicate = []() -> bool { return false; };
	auto truePredicate = []() { return true; };

	IDamagable* e = new Entity();
	std::cout << e->takeDamageIf(10, falsePredicate) << std::endl;
	std::cout << e->takeDamageIf(10, truePredicate) << std::endl;
	delete e;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

