#ifndef SDK_SWAPCHAIN_HPP
#define SDK_SWAPCHAIN_HPP

#include <memory>

#include <dxgi.h>

class SwapChain
{
public:
	SwapChain();

private:
	std::unique_ptr<IDXGISwapChain*> swapchain_;
};

#endif
