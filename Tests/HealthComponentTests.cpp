#include <gtest/gtest.h>
#include "../HealthComponent.h"

class HealthComponentTest : public testing::Test {
protected:
  HealthComponent hc{};
  HealthComponent hc1{100};
  HealthComponent hc1in{-100};
  HealthComponent hc2{100, 50};
  HealthComponent hc2i{100, 250};
  HealthComponent hc2in{100, -50};
  //hc - no arguments, hc1 - 1 argument
  //i - invalid, n - negative value

  HealthComponentTest(){}

  void SetUp() override {}
  void TearDown() override {}

  ~HealthComponentTest(){}
};

TEST_F(HealthComponentTest, defaultConstructorAsserts){

  ASSERT_EQ(hc.getHealthPoints(), 0);
  ASSERT_EQ(hc.getMaxHealthPoints(), 0);

}

TEST_F(HealthComponentTest, oneArgumentConstructorAsserts){

  EXPECT_EQ(hc1.getHealthPoints(), 100);
  EXPECT_EQ(hc1.getMaxHealthPoints(), 100);

  ASSERT_EQ(hc1in.getHealthPoints(), 0);
  ASSERT_EQ(hc1in.getMaxHealthPoints(), 0);

}

TEST_F(HealthComponentTest, twoArgumentConstructorAsserts){
  
  EXPECT_EQ(hc2.getHealthPoints(), 50);
  EXPECT_EQ(hc2.getMaxHealthPoints(), 100);

  EXPECT_EQ(hc2i.getHealthPoints(), 100);
  EXPECT_EQ(hc2i.getMaxHealthPoints(), 100);

  EXPECT_EQ(hc2in.getHealthPoints(), 0);
  EXPECT_EQ(hc2in.getMaxHealthPoints(), 100);

}

TEST_F(HealthComponentTest, isDeadStateInitiatedCorrectly){
  
  EXPECT_FALSE(hc1.isDead());
  EXPECT_FALSE(hc2.isDead());
  EXPECT_FALSE(hc2i.isDead());

  EXPECT_TRUE(hc.isDead());
  EXPECT_TRUE(hc1in.isDead());
  EXPECT_TRUE(hc2in.isDead());

}

TEST_F(HealthComponentTest, damageTakingAsserts){

  EXPECT_EQ(hc1.takeDamage(200), 100);
  EXPECT_EQ(hc1.getHealthPoints(), 0);
  EXPECT_EQ(hc1.getMaxHealthPoints(), 100);
  ASSERT_TRUE(hc1.isDead());
  
  EXPECT_EQ(hc2.takeDamage(10), 10);
  EXPECT_EQ(hc2.getHealthPoints(), 40);
  EXPECT_EQ(hc2.getMaxHealthPoints(), 100);
  
  EXPECT_EQ(hc2.takeDamage(40), 40);
  EXPECT_EQ(hc2.getHealthPoints(), 0);
  EXPECT_EQ(hc2.getMaxHealthPoints(), 100);
  ASSERT_TRUE(hc2.isDead());

}

TEST_F(HealthComponentTest, healingAsserts){
  
  EXPECT_EQ(hc1.takeDamage(200), 100);
  EXPECT_EQ(hc1.getHealthPoints(), 0);
  EXPECT_EQ(hc1.getMaxHealthPoints(), 100);
  ASSERT_TRUE(hc1.isDead());

  EXPECT_EQ(hc1.getHeal(20), 20);
  EXPECT_EQ(hc1.getHealthPoints(), 20);
  EXPECT_EQ(hc1.getMaxHealthPoints(), 100);
  ASSERT_FALSE(hc1.isDead());

  EXPECT_EQ(hc1.getHeal(200), 80);
  EXPECT_EQ(hc1.getHealthPoints(), 100);
  EXPECT_EQ(hc1.getMaxHealthPoints(), 100);
  ASSERT_FALSE(hc1.isDead());

}
