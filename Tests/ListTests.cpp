#include <gtest/gtest.h>
#include "../List.h"
#include <string>

class ListTest : public testing::Test {
protected:
	
	const int INT_POSITIVE{ 10 };
	const int INT_NEGATIVE{ -10 };
	const double DOUBLE_POSITIVE{ 10.0 };
	const double DOUBLE_NEGATIVE{ -10.0 };
	const std::string EMPTY_STRING{" "};
	const std::string STRING{"abcd1234!?="};

	List<int>* ilist{ nullptr };
	List<double>* dlist{ nullptr };
	List<std::string>* slist{ nullptr };
	
	ListTest() {
		ilist = new List<int>();
		dlist = new List<double>();
		slist = new List<std::string>();
	}

	~ListTest() override {
		ilist->~List();
		dlist->~List();
		slist->~List();

		delete ilist, dlist, slist;
	}

	void SetUp() override {

	}

	void TearDown() override {

	}
};

TEST_F(ListTest, IsInitiallyEmpty) {
	EXPECT_TRUE(ilist->empty());
	EXPECT_TRUE(dlist->empty());
	EXPECT_TRUE(slist->empty());

	ASSERT_EQ(ilist->size(), 0);
	ASSERT_EQ(dlist->size(), 0);
	ASSERT_EQ(slist->size(), 0);
}

TEST_F(ListTest, HandlesIntegers) {
	ilist->push_back(INT_POSITIVE);
	ilist->push_back(INT_NEGATIVE);
	ASSERT_EQ(ilist->at(0), INT_POSITIVE);
	ASSERT_EQ(ilist->at(1), INT_NEGATIVE);
	ASSERT_EQ(*(ilist->pop_back()), INT_NEGATIVE);
	ASSERT_EQ(*(ilist->pop_back()), INT_POSITIVE);
	ASSERT_TRUE(ilist->empty());
	ASSERT_EQ(ilist->size(), 0);
}

TEST_F(ListTest, HandlesDoubles) {
	dlist->push_back(DOUBLE_POSITIVE);
	dlist->push_back(DOUBLE_NEGATIVE);
	ASSERT_EQ(dlist->at(0), DOUBLE_POSITIVE);
	ASSERT_EQ(dlist->at(1), DOUBLE_NEGATIVE);
	ASSERT_EQ(*(dlist->pop_back()), DOUBLE_NEGATIVE);
	ASSERT_EQ(*(dlist->pop_back()), DOUBLE_POSITIVE);
	ASSERT_TRUE(dlist->empty());
	ASSERT_EQ(dlist->size(), 0);
}

TEST_F(ListTest, HandlesStrings) {
	slist->push_back(EMPTY_STRING);
	slist->push_back(STRING);
	ASSERT_EQ(slist->at(0), EMPTY_STRING);
	ASSERT_EQ(slist->at(1), STRING);
	ASSERT_EQ(*(slist->pop_back()), STRING);
	ASSERT_EQ(*(slist->pop_back()), EMPTY_STRING);
	ASSERT_TRUE(slist->empty());
	ASSERT_EQ(slist->size(), 0);
}
