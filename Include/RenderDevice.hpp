#ifndef SDK_RENDERDEVICE_HPP
#define SDK_RENDERDEVICE_HPP

#include <Unknwn.h>

class RenderDevice
{
public:
	virtual IUnknown* GetRealRenderDevice() { return nullptr; }
};

#endif
