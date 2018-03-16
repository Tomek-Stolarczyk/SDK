#pragma once

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class Window
{
public:
	Window();
	
	bool Create(const std::string window_name, int width, int height);

private:
  HWND _handle;
};