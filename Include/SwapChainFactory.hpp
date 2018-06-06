#ifndef SDK_SWAPCHAINFACTORY_HPP
#define SDK_SWAPCHAINFACTORY_HPP

#include "SwapChain.hpp"

#include <memory>

#include <dxgi.h>

class SwapChainFactory
{
public:
	SwapChainFactory();
	SwapChain CreateSwapChain();

private:
	std::unique_ptr<IDXGIFactory> factory_;
};

#endif


