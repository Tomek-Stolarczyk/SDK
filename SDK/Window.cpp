#include "Window.hpp"

#include <exception>
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
    if (0 == RegisterClassA(&wc))
    {
      throw "RegisterClass failed";
    }
    return className;
  }
}

Window::Window() :
  _handle(NULL)
{
}

bool Window::Create(const std::string window_name, int width, int height)
{
  const DWORD style = WS_OVERLAPPEDWINDOW;
  RECT desktop;
  GetWindowRect(GetDesktopWindow(), &desktop);
  const int x = (desktop.right / 2) - (width / 2);
  const int y = (desktop.bottom / 2) - (height / 2); 
  _handle = CreateWindowExA(0, RegisterName().c_str(), window_name.c_str(), style, x, y,
               width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
  if (_handle == NULL)
  {
    throw "CreateWindowExA failed";
  }
  ShowWindow(_handle, SW_SHOW);
  return true;
}
