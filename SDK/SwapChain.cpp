#include "SwapChain.hpp"

#include <utility>
namespace SDK
{
namespace SwapChain
{
  SwapChain::SwapChain(COM<IDXGISwapChain>&& swapChain) :
    swapChain_(std::forward<COM<IDXGISwapChain>>(swapChain))
  {
  };
} // namespace SwapChain
} // namespace SDK
