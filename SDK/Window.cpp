#include "Window.hpp"

#include <string>

#include "Windows.h"

namespace
{
  const std::string RegisterName()
  {
    std::string className = "Default class Name";
    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = className.c_str();
    RegisterClass(&wc);
    return className;
  }
}

Window::Window()
{
}

bool Window::Create(const std::string window_name, int width, int height)
{
  const std::string&& class_name = RegisterName();
  const DWORD style = WS_OVERLAPPEDWINDOW;
  RECT desktop;
  GetWindowRect(GetDesktopWindow(), &desktop);
  const int x = desktop.right / 2;
  const int y = desktop.bottom / 2;
  CreateWindow(class_name.c_str(), window_name, style, x, y, width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
}
