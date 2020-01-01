#ifndef SDK_SWAPCHAINFACTORY_HPP
#define SDK_SWAPCHAINFACTORY_HPP

#include "SwapChain.hpp"
#include "COMPointer.hpp"
#include "RenderDevice.hpp"

#include <memory>

#include <dxgi.h>

class SwapChainFactory
{
public:
	SwapChainFactory();
	SwapChain CreateSwapChain(RenderDevice* device, DXGI_SWAP_CHAIN_DESC* desc);

private:
	COM<IDXGIFactory> factory_;
};

#endif
