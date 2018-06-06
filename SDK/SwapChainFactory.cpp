#include "SwapChainFactory.hpp"

#pragma comment(lib, "dxgi.lib")

SwapChainFactory::SwapChainFactory()
{
	CreateDXGIFactory(IID_PPV_ARGS(&factory_));
}

SwapChain SwapChainFactory::CreateSwapChain()
{
	return SwapChain();
}

int main()
{
	SwapChainFactory newFactory;
}