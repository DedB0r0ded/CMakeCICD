#include <gtest/gtest.h>
#include "../Items/Item.h"

class ItemTest : public ::testing::Test {
protected:
  Item* item;

  ItemTest() : item{} {
    
  }

  ~ItemTest(){
  
  }

  void SetUp() override{
    item = new Item;
  }
  void TearDown() override{
    delete item;
  }
};


TEST_F(ItemTest, DefaultConstructorAssertions) {
  Item& ref = *item;
  ASSERT_NE(item, nullptr);
  ASSERT_EQ(ref.id(), 0);
  ASSERT_EQ(ref.name(), "none");
}