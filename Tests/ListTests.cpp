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
	ASSERT_EQ(ilist->at(0), INT_POSITIVE) << "Failed to locate a positive integer value";
	ASSERT_EQ(ilist->at(1), INT_NEGATIVE) << "Failed to locate a negative integer value";
	int* popped = ilist->pop_back();
	ASSERT_EQ(*popped, INT_NEGATIVE) << "Failed to pop a negative integer value";
	delete popped;
	popped = ilist->pop_back();
	ASSERT_EQ(*popped, INT_POSITIVE) << "Failed to locate a positive integer value";
	delete popped;
	ASSERT_TRUE(ilist->empty());
	ASSERT_EQ(ilist->size(), 0);
}

TEST_F(ListTest, HandlesDoubles) {
	dlist->push_back(DOUBLE_POSITIVE);
	dlist->push_back(DOUBLE_NEGATIVE);
	ASSERT_EQ(dlist->at(0), DOUBLE_POSITIVE) << "Failed to locate positive double value";
	ASSERT_EQ(dlist->at(1), DOUBLE_NEGATIVE) << "Failed to locate negative double value";
	double* popped = dlist->pop_back();
	ASSERT_EQ(*popped, DOUBLE_NEGATIVE) << "Failed to pop negative double value";
	delete popped;
	popped = dlist->pop_back();
	ASSERT_EQ(*popped, DOUBLE_POSITIVE) << "Failed to pop positive double value";
	delete popped;
	ASSERT_TRUE(dlist->empty());
	ASSERT_EQ(dlist->size(), 0);
}

TEST_F(ListTest, HandlesStrings) {
	slist->push_back(EMPTY_STRING);
	slist->push_back(STRING);
	ASSERT_EQ(slist->at(0), EMPTY_STRING) << "Failed to locate an empty string";
	ASSERT_EQ(slist->at(1), STRING) << "Failed to locate a string";
	std::string* popped = slist->pop_back();
	ASSERT_EQ(*popped, STRING) << "Failed to pop a string";
	delete popped;
	popped = slist->pop_back();
	ASSERT_EQ(*popped, EMPTY_STRING) << "Failed to pop an empty string";
	delete popped;
	ASSERT_TRUE(slist->empty());
	ASSERT_EQ(slist->size(), 0);
}
