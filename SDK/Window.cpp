#include "Window.hpp"

#include <exception>

namespace {
  const std::wstring RegisterName()
  {
    std::wstring className = L"Default class Name";
    WNDCLASSW wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = className.c_str();
    if (0 == RegisterClassW(&wc))
    {
      throw "RegisterClass failed";
    }
    return className;
  }

  void ThrowIfWindowNull(HWND window)
  {
    if (NULL == window)
    {
      throw "Window not initialized.";
    }
  }
}

namespace SDK {
namespace Window {

Window::Window() :
  handle_(NULL)
{
}

Window::~Window()
{
  try
  {
    Destroy();
  }
  catch (...)
  {

  }
}

void Window::Create(const std::wstring_view window_name, size_t width, size_t height)
{
  if ((width == 0) ||
    (height == 0) ||
    (window_name.empty()))
  {
    throw "Invalid Arguments. Width and Height must be non-zero and window_name must be non-empty";
  }

  if (NULL != handle_)
  {
    throw "Creation called multiple times";
  }

  const DWORD style = WS_OVERLAPPEDWINDOW;
  RECT desktop;
  GetWindowRect(GetDesktopWindow(), &desktop);
  const int x = (desktop.right / 2) - (static_cast<int>(width) / 2);
  const int y = (desktop.bottom / 2) - (static_cast<int>(height) / 2); 
  handle_ = CreateWindowExW(0, RegisterName().c_str(), window_name.data(), style, x, y,
               static_cast<int>(width), static_cast<int>(height), NULL, NULL, GetModuleHandle(NULL), NULL);
  if (handle_ == NULL)
  {
    throw "CreateWindowExW failed";
  }
}

void Window::Destroy()
{
  if (handle_ != NULL)
  {
    DestroyWindow(handle_);
    handle_ = NULL;
  }
}

void Window::MoveRelative(int x, int y)
{
  ThrowIfWindowNull(handle_);
  RECT window_rect;
  ::GetWindowRect(handle_, &window_rect);
  const int width = window_rect.left - window_rect.right;
  const int height = window_rect.top - window_rect.bottom;
  window_rect.top += x;
  window_rect.left += y;
  ::MoveWindow(handle_, window_rect.left, window_rect.top, width, height, FALSE);
}

void Window::MoveAbsolute(size_t x, size_t y)
{
  ThrowIfWindowNull(handle_);
  RECT window_rect;
  ::GetWindowRect(handle_, &window_rect);
  const int width = window_rect.left - window_rect.right;
  const int height = window_rect.top - window_rect.bottom;
  ::MoveWindow(handle_, static_cast<int>(x), static_cast<int>(y), width, height, FALSE);
}

std::pair<size_t, size_t> Window::GetPosition()
{
  ThrowIfWindowNull(handle_);
  RECT window_rect;
  ::GetWindowRect(handle_, &window_rect);
  return std::make_pair(window_rect.top, window_rect.left);
}

std::pair<size_t, size_t> Window::GetSize()
{
  ThrowIfWindowNull(handle_);
  RECT window_rect;
  ::GetWindowRect(handle_, &window_rect);
  return std::make_pair(window_rect.left - window_rect.right, window_rect.top - window_rect.bottom);
}

void Window::ShowWindow()
{
  ThrowIfWindowNull(handle_);
  ::ShowWindow(handle_, SW_SHOW);
}

void Window::HideWindow()
{
  ThrowIfWindowNull(handle_);
  ::ShowWindow(handle_, SW_HIDE);
}

bool Window::IsVisible()
{
  return false;
}

} // namespace SDK  
} // namespace Window
