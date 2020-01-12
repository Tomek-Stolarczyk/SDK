#include "compointer.hpp"
#include "RenderDevice.hpp"

#ifndef SDK_SURFACE_HPP
#define SDK_SURFACE_HPP

namespace SDK
{
namespace Texture2D
{
  class Texture2D
  {
  public:
    Texture2D(COM<ID3D11Texture2D>&& texture);
    virtual ~Texture2D() = default;
  private:
    COM<ID3D11Texture2D> _texture;
  };
}

namespace Surface
{
  class Surface
  {
  };
} // namespace Surface
} // namespace SDK

#endif !SDK_SURFACE_HPP