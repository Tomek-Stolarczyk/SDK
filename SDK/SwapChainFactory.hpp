#ifndef SDK_SWAPCHAINFACTORY_HPP
#define SDK_SWAPCHAINFACTORY_HPP

#include "SwapChain.hpp"
#include "COMPointer.hpp"

#include <memory>

#include <dxgi.h>

class SwapChainFactory
{
public:
	SwapChainFactory();
	SwapChain CreateSwapChain();

private:
	COM<IDXGIFactory> factory_;
};

#endif


