#include "Window.hpp"

#include "gtest\gtest.h"

class WindowTest : public ::testing::Test {
protected:
  virtual void SetUp() 
  {
  }

  virtual void TearDown() 
  {
  }
};

TEST_F(WindowTest, Creation)
{
  SDK::Window::Window new_window;
  ASSERT_NO_THROW(new_window.Create(L"new Window", 240, 100));
}

TEST_F(WindowTest, Creation_Failure)
{
  SDK::Window::Window new_window;
  ASSERT_ANY_THROW(new_window.Create(L"", 240, 100));
  ASSERT_ANY_THROW(new_window.Create(L"valid", 0, 12));
  ASSERT_ANY_THROW(new_window.Create(L"valid", 0, 0));
  ASSERT_ANY_THROW(new_window.Create(L"valid", 12, 0));
}

TEST_F(WindowTest, Size)
{
  SDK::Window::Window new_window;
  ASSERT_NO_THROW(new_window.Create(L"new Window", 240, 100));
  ASSERT_EQ(new_window.GetSize().first, 240);
  ASSERT_EQ(new_window.GetSize().second, 100);
}