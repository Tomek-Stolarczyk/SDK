#include "Window.hpp"

#include <exception>

namespace
{
  void WindowClass()
  {
    MSG msg{  };
    while (GetMessage(&msg, NULL, 0, 0))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  const std::wstring RegisterName()
  {
    const std::wstring className{ L"Default class Name" };
    WNDCLASSW wc{  };
    wc.lpfnWndProc = reinterpret_cast<WNDPROC>(WindowClass);
    wc.hInstance = GetModuleHandle(NULL); // TODO get the handle from exe and shove into here, not dll
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

namespace SDK 
{
namespace Window
{

  Window::Window(const std::wstring_view window_name,
    size_t width, size_t height) :
    _handle(NULL)
  {
    const DWORD style{ WS_OVERLAPPEDWINDOW };
    RECT desktop{  };
    GetWindowRect(GetDesktopWindow(), &desktop);
    const int x{ (desktop.right / 2) - (static_cast<int>(width) / 2) };
    const int y{ (desktop.bottom / 2) - (static_cast<int>(height) / 2) };
    _handle = CreateWindowExW(0, RegisterName().c_str(), window_name.data(),
      style, x, y,
      static_cast<int>(width), static_cast<int>(height),
      NULL, NULL, GetModuleHandle(NULL), NULL);
    if (_handle == NULL)
    {
      throw "CreateWindowExW failed";
    }
  }

  Window::~Window()
  {
    DestroyWindow(GetHWND());
    _handle = NULL;
  }

  void Window::MoveRelative(int x, int y)
  {
    ThrowIfWindowNull(GetHWND());
    RECT window_rect{  };
    ::GetWindowRect(GetHWND(), &window_rect);
    const int width{ window_rect.left - window_rect.right };
    const int height{ window_rect.top - window_rect.bottom };
    window_rect.top += x;
    window_rect.left += y;
    ::MoveWindow(GetHWND(), window_rect.left, window_rect.top,
      width, height, FALSE);
  }

  void Window::MoveAbsolute(size_t x, size_t y)
  {
    ThrowIfWindowNull(GetHWND());
    RECT window_rect{  };
    ::GetWindowRect(GetHWND(), &window_rect);
    const int width{ window_rect.left - window_rect.right };
    const int height{ window_rect.top - window_rect.bottom };
    ::MoveWindow(GetHWND(), static_cast<int>(x), static_cast<int>(y),
                  width, height, FALSE);
  }

  std::pair<size_t, size_t> Window::GetPosition()
  {
    ThrowIfWindowNull(GetHWND());
    RECT window_rect{  };
    ::GetWindowRect(GetHWND(), &window_rect);
    return std::make_pair(window_rect.top, window_rect.left);
  }

  std::pair<size_t, size_t> Window::GetSize()
  {
    ThrowIfWindowNull(GetHWND());
    RECT window_rect{  };
    ::GetWindowRect(GetHWND(), &window_rect);
    return std::make_pair(window_rect.left - window_rect.right,
                          window_rect.top - window_rect.bottom);
  }

  void Window::ShowWindow()
  {
    ThrowIfWindowNull(GetHWND());
    ::ShowWindow(GetHWND(), SW_SHOW);
  }

  void Window::HideWindow()
  {
    ThrowIfWindowNull(GetHWND());
    ::ShowWindow(GetHWND(), SW_HIDE);
  }

  bool Window::IsVisible()
  {
    return false;
  }

  HWND Window::GetHWND() const
  {
    return _handle;
  }

} // namespace Window  
} // namespace SDK
