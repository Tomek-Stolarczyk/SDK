#include "SwapChainFactory.hpp"

#include <assert.h>

namespace SDK
{
namespace SwapChainFactory
{
  SwapChainFactory::SwapChainFactory()
  {
    HRESULT result = CreateDXGIFactory(IID_PPV_ARGS(&factory_));
    assert(S_OK == result);
  }

  SwapChain::SwapChain SwapChainFactory::CreateSwapChain(
    const RenderDevice::RenderDevice* device,
    const DXGI_SWAP_CHAIN_DESC* desc)
  {
    COM<IDXGISwapChain> new_swap;
    HRESULT result = factory_->CreateSwapChain(
      device->GetRealRenderDevice(),
      const_cast<DXGI_SWAP_CHAIN_DESC*>(desc),
      &new_swap);
    assert(S_OK == result);
    return SwapChain::SwapChain(std::move(new_swap));
  }
} // namespace SwapChainFactory
} // namespace SDK
