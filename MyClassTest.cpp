//
// Created by Vladimir Moiseiev on 13.07.2020.
//

#include <gtest/gtest.h>

#include "MyClass.h"

class MyClassTest : public ::testing::Test {

};

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


