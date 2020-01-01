#include "SwapChainFactory.hpp"

#include <assert.h>

SwapChainFactory::SwapChainFactory()
{
	HRESULT result = CreateDXGIFactory(IID_PPV_ARGS(&factory_));
	assert(S_OK == result);
}

SwapChain SwapChainFactory::CreateSwapChain(RenderDevice* device,
                                            DXGI_SWAP_CHAIN_DESC* desc)
{
	COM<IDXGISwapChain> newSwapChain;
	factory_->CreateSwapChain(device->GetRealRenderDevice(),
                            desc, &newSwapChain);
	return SwapChain(std::move(newSwapChain));
}