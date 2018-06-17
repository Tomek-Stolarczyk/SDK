#ifndef SDK_SWAPCHAIN_HPP
#define SDK_SWAPCHAIN_HPP

#include "COMPointer.hpp"

#include <memory>

#include <dxgi.h>

class SwapChain
{
public:
	SwapChain(COM<IDXGISwapChain> &&swapChain);

private:
	COM<IDXGISwapChain> swapChain_;
};

#endif