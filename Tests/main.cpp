#include "Point_tests.h"
#include "Direction_tests.h"
#include "Snake_tests.h"

#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	std::cin.get();

	return result;
}