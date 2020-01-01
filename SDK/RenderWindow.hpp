#ifndef SDK_RENDERWINDOW_HPP
#define SDK_RENDERWINDOW_HPP

#include <string_view>

#include "Window.hpp"

namespace SDK
{
namespace RenderWindow
{
  class RenderWindow : public Window::Window
  {
  public:
    RenderWindow(const RenderDevice,
      const std::wstring_view window_name,
      size_t width, size_t height);
    virtual ~RenderWindow();
     
    RenderWindow(const RenderWindow&) = delete;
    RenderWindow& operator=(const RenderWindow&) = delete;

    RenderWindow(RenderWindow&&) = delete;
    RenderWindow&& operator=(RenderWindow&&) = delete;

  private:
    HWND handle_;
  };

} // namespace RenderWindow
} // namespace SDK

#endif // !_SDK_RENDERWINDOW_HPP_
