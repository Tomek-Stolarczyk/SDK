#ifndef SDK_RENDERWINDOW_HPP
#define SDK_RENDERWINDOW_HPP

#include <string_view>

#include "Window.hpp"
#include "RenderDevice.hpp"
#include "Surface.hpp"
#include "SwapChain.hpp"
#include "SwapChainFactory.hpp"


namespace SDK
{
namespace RenderWindow
{
  class RenderWindow : public Window::Window
  {
  public:
    RenderWindow(const RenderDevice::RenderDevice* device,
      const std::wstring_view window_name,
      size_t width, size_t height);
    virtual ~RenderWindow();
     
    RenderWindow(const RenderWindow&) = delete;
    RenderWindow& operator=(const RenderWindow&) = delete;

    RenderWindow(RenderWindow&&) = delete;
    RenderWindow&& operator=(RenderWindow&&) = delete;

  private:
    DXGI_SWAP_CHAIN_DESC PopulateSwapDesc(size_t width, size_t height);

    SwapChainFactory::SwapChainFactory factory_;
    SwapChain::SwapChain _swapchain;
    DXGI_SWAP_CHAIN_DESC _desc;
  };

} // namespace RenderWindow
} // namespace SDK

#endif // !SDK_RENDERWINDOW_HPP_
