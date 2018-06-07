#ifndef SDK_WINDOW_HPP
#define SDK_WINDOW_HPP 

#include <string_view>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace SDK {
namespace Window {


class Window
{
public:
	Window();
  ~Window();
	
	void Create(std::wstring_view window_name, size_t width, size_t height);
  void Destroy();
  void MoveRelative(int x, int y);
  void MoveAbsolute(size_t x, size_t y);
  std::pair<size_t, size_t> GetPosition();
  std::pair<size_t, size_t> GetSize();
  void ShowWindow();
  void HideWindow();
  bool IsVisible();

private:
  HWND handle_;
};

} // namespace SDK
} // namespace Window

#endif // !_SDK_WINDOW_HPP_
