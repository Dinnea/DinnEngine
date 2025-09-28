#pragma once
#ifdef DN_PLATFORM_WINDOWS
	#ifdef DN_BUILD_DLL
	#define DINN_API __declspec(dllexport)
	#else
	#define DINN_API __declspec(dllimport)	
	#endif // DN_BUILD_DLL
#endif // DN_PLATFORM_WINDOWS

#ifdef DN_ENABLE_ASSERTS
	#define DN_ASSERT (x, ...) {if(!(x)){DN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define DN_CORE_ASSERT (x, ...) {if(!(x)){DN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define DN_ASSERT(x, ...)
	#define DN_CORE_ASSERT(x, ...)
#endif // DN_ENABLE_ASSERTS

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1<<x)
