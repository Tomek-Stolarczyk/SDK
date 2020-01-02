#ifndef SDK_SWAPCHAINFACTORY_HPP
#define SDK_SWAPCHAINFACTORY_HPP

#include "SwapChain.hpp"
#include "COMPointer.hpp"
#include "RenderDevice.hpp"

#include <memory>

#include <dxgi.h>

namespace SDK
{
namespace SwapChainFactory
{
  class SwapChainFactory
  {
  public:
    SwapChainFactory();

    SwapChain::SwapChain CreateSwapChain(
      const RenderDevice::RenderDevice* device,
      const DXGI_SWAP_CHAIN_DESC* desc);

  private:
    COM<IDXGIFactory> factory_;
  };

} // namespace SwapChainFactory
} // namespace SDK

#endif // !_SDK_SWAPCHAINFACTORY_HPP_
