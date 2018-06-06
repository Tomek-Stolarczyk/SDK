#include "Window.hpp"

#include "gtest\gtest.h"

TEST(WindowTest, Creation)
{
  Window newWindow;
  newWindow.Create("new Window", 240, 100);
  ASSERT_TRUE(true);
}