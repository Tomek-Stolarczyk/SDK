#include "SwapChain.hpp"

#include <utility>

SwapChain::SwapChain(COM<IDXGISwapChain>&& swapChain) :
	swapChain_(std::forward<COM<IDXGISwapChain>>(swapChain))
{
}
