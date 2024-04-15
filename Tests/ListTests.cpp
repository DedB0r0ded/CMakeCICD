#include <gtest/gtest.h>
#include "../List.h"

template <typename T>
std::shared_ptr<List<T>> makeMyList_test() {
	std::shared_ptr<List<T>> l = std::make_shared<List<int>>();
	return l;
}

TEST(ListTests, BasicAssertions) {
	auto l = makeMyList_test<int>();
  EXPECT_NE(l, nullptr);
	ASSERT_TRUE(l->empty());
	l->push_back(10);
	EXPECT_EQ(l->at(0), 10);
	ASSERT_FALSE(l->empty());
}
