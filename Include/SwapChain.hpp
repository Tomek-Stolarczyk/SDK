#ifndef SDK_SWAPCHAIN_HPP
#define SDK_SWAPCHAIN_HPP

#include "COMPointer.hpp"

#include <dxgi.h>

namespace SDK
{
namespace SwapChain
{
  class SwapChain
  {
  public:
    virtual ~SwapChain() = default;
    SwapChain(COM<IDXGISwapChain>&& swapChain);

  private:
    COM<IDXGISwapChain> swapChain_;
  };
} // namespace SwapChain
} // namespace SDK

#endif // !SDK_SWAPCHAIN_HPP