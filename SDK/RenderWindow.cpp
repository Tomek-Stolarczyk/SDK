#include "RenderWindow.hpp"

#include <string_view>

#include "Window.hpp"
#include "RenderDevice.hpp"

namespace SDK
{
namespace RenderWindow
{
  RenderWindow::RenderWindow(const RenderDevice::RenderDevice* device,
    const std::wstring_view window_name, size_t width, size_t height) :
      Window(window_name, width, height),
      _desc(PopulateSwapDesc(width, height)),
      _swapchain(factory_.CreateSwapChain(device, &_desc))
  {
  }
    
  RenderWindow::~RenderWindow()
  {
  }

  DXGI_SWAP_CHAIN_DESC RenderWindow::PopulateSwapDesc(size_t width, size_t height)
  {
    DXGI_SWAP_CHAIN_DESC desc{  };
    desc.BufferCount = 2;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UINT;
    desc.BufferDesc.Height = static_cast<UINT>(height);
    desc.BufferDesc.Width = static_cast<UINT>(width);
    desc.BufferDesc.RefreshRate = { 1, 30 };
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.Flags = 0;
    desc.OutputWindow = GetHWND();
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 1;
    desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    desc.Windowed = true;
    return desc;
  }

} // namespace RenderWindow
} // namespace SDK
