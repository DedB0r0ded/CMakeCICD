#include <gtest/gtest.h>

TEST(ListTests, BasicAssertions) {
	ASSERT_TRUE(true);
	ASSERT_FALSE(false);
	EXPECT_EQ(1, 1);
}
