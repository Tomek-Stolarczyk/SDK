#include "RenderDevice.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <d3d11.h>

SDK::RenderDevice::DX11RenderDevice::DX11RenderDevice()
{
  HRESULT hr{ D3D11CreateDevice(NULL,
                                D3D_DRIVER_TYPE_HARDWARE,
                                NULL,
                                0,
                                NULL,
                                0,
                                D3D11_SDK_VERSION,
                                &_device,
                                nullptr,
                                nullptr) };
}

SDK::RenderDevice::DX11RenderDevice::~DX11RenderDevice()
{
}
 
IUnknown* SDK::RenderDevice::DX11RenderDevice::GetRealRenderDevice() const
{
  return _device.get();
}
