
#include "observer.h"
#include "subject.h"

#include "gtest/gtest.h"
#include <QtCore/QVariant>
#include <QtCore/QtDebug>
#include <QtWidgets/QApplication>
#include <iostream>
#include <stdio.h>
using namespace robosense::lidar;

// 此函数用于判断入参是否为正整数：如果是，则返回0；否则，返回-1
int Positive(int nNum)
{
  if (nNum > 0)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

// 测试入参2是否为正整数
TEST(PositiveTest, HandlesPositiveInput) { EXPECT_EQ(Positive(2), 0) << "25455555"; }

// 定义测试类FooTest
class FooTest : public testing::Test
{
protected:
  // Code here will be called immediately after the constructor (right before each test)
  void SetUp() { m_nTarget = 5; }

  // Code here will be called immediately after each test (right before the destructor)
  void TearDown() {}

public:
  int IsLargeThan5(const int& nNum);
  int m_nTarget;
};

// 判断入参是否大于5：如果是，则返回0；否则返回-1
int FooTest::IsLargeThan5(const int& nNum)
{
  if (nNum > m_nTarget)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

TEST_F(FooTest, HandlesInput6) { EXPECT_EQ(IsLargeThan5(6), 0); }

TEST_F(FooTest, HandlesInput5) { EXPECT_EQ(IsLargeThan5(5), 0); }

TEST_F(FooTest, HandlesInput4) { EXPECT_EQ(IsLargeThan5(4), -1); }

int main(int argc, char* argv[])
{
  // 分析gtest程序的命令行参数
  testing::InitGoogleTest(&argc, argv);

  // 调用RUN_ALL_TESTS()运行所有测试用例
  // main函数返回RUN_ALL_TESTS()的运行结果
  return RUN_ALL_TESTS();
}
