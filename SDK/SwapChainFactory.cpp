#include "SwapChainFactory.hpp"
#include <assert.h>

#pragma comment(lib, "dxgi.lib")

SwapChainFactory::SwapChainFactory()
{
	HRESULT result = CreateDXGIFactory(IID_PPV_ARGS(&factory_));
	assert(S_OK == result);
}

SwapChain SwapChainFactory::CreateSwapChain(RenderDevice device, DXGI_SWAP_CHAIN_DESC* desc)
{
	COM<IDXGISwapChain> newSwapChain;
	factory_->CreateSwapChain(device.GetRealRenderDevice(), desc, &newSwapChain);
	return SwapChain(std::forward<COM<IDXGISwapChain>>(newSwapChain));
}

int main()
{
	SwapChainFactory newFactory;
}