#include "Surface.hpp"

#include <utility>
#include <d3d11.h>

namespace SDK
{
namespace Texture2D
{
  Texture2D::Texture2D(COM<ID3D11Texture2D>&& texture) :
    _texture(std::forward<COM<ID3D11Texture2D>>(texture))
  {
  }
}

namespace Surface
{

} // namespace Surface
} // namespace SDK
