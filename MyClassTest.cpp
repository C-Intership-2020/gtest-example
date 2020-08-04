//
// Created by Vladimir Moiseiev on 13.07.2020.
//

#include <gtest/gtest.h>
#include <stdexcept>

#include "MyClass.h"

class MyClassTest : public ::testing::Test {

};

struct X{
  int date;
};

X createX(int month)
{
  if(month < 1 || month > 12)
  {
    throw std::runtime_error{""};
  }
  X x;
  x.date = month; //1-12

  return x;
}

TEST_F(MyClassTest, testX)
{
  X x = createX(5);
  ASSERT_EQ(5 , x.date);
}

TEST_F(MyClassTest, testXValidation)
{
  EXPECT_THROW(createX(55),std::runtime_error);
  EXPECT_THROW(createX(0),std::runtime_error);
}




TEST_F(MyClassTest, shouldReturn1)
{
  MyClass my;
  ASSERT_EQ(1 , my.getval());
  ASSERT_EQ(1 , my.getval());
}

TEST_F(MyClassTest, shouldCreatePointer)
{
  auto ptr = MyClass::make();
  ASSERT_TRUE(ptr);
  ASSERT_EQ(10 , ptr->GetState());
}

class A{
 public:
  //bool operator==(const A&) {return true;}

};
//-------------------
bool operator==(const A&, const A&) {
  return true;
}









