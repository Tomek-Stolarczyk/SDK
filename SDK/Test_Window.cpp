#include "Window.hpp"

#include "gtest\gtest.h"

TEST(WindowTest, Creation)
{
  Window newWindow;
  newWindow.Create("new Window", 240, 100);
  ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}