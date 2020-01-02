#ifndef SDK_WINDOW_HPP
#define SDK_WINDOW_HPP 

#include <string_view>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace SDK
{
namespace Window
{

class Window
{
public:
  Window(const std::wstring_view window_name,
    size_t width, size_t height);
  virtual ~Window();
  
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  Window(Window&&) = delete;
  Window&& operator=(Window&&) = delete;

  void MoveRelative(int x, int y);
  void MoveAbsolute(size_t x, size_t y);
  std::pair<size_t, size_t> GetPosition();
  std::pair<size_t, size_t> GetSize();
  void ShowWindow();
  void HideWindow();
  bool IsVisible();

protected:
  HWND GetHWND() const;

private:
  HWND _handle;
};

} // namespace Window
} // namespace SDK

#endif // !_SDK_WINDOW_HPP_
