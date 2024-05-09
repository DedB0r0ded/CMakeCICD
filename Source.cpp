#include "Header.h"

int main(int argc, char** argv)
{
	uint8_t n = 120;
	std::cout << (int)n << std::endl;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

