﻿#include "Header.h"

int main(int argc, char** argv)
{
	std::cout << argc;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

