#include <gtest/gtest.h>

namespace robosense
{
namespace lidar
{

TEST(HelloTest, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

}  // namespace lidar
}  // namespace robosense