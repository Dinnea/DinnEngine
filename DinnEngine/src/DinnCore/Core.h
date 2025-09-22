#pragma once
#ifdef DN_PLATFORM_WINDOWS
#ifdef DN_BUILD_DLL
#define DINN_API __declspec(dllexport)
#else
#define DINN_API __declspec(dllimport)	
#endif // DN_BUILD_DLL
#endif // DN_PLATFORM_WINDOWS

#define BIT(x) (1<<x)