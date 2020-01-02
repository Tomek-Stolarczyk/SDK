#ifndef SDK_RENDERDEVICE_HPP
#define SDK_RENDERDEVICE_HPP

#include <Unknwn.h>
#include <d3d11.h>

#include "compointer.hpp"

namespace SDK
{
namespace RenderDevice
{
  class RenderDevice
  {
  public:
    virtual IUnknown* GetRealRenderDevice() const = 0;
  };

  class DX11RenderDevice final : public RenderDevice
  {
  public:
    DX11RenderDevice();
    ~DX11RenderDevice();

    IUnknown* GetRealRenderDevice() const override;
  private:
    COM<ID3D11Device> _device;
  };
} // namespace RenderDevice
} // namespace SDK

#endif // !_SDK_RENDERDEVICE_HPP_
