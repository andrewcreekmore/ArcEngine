#pragma once

/*
===========================================================================
Core.h: macro definitions
- defines ARCENGINE_API macro as __declspec import/export where needed
- defines ArcEngine assert macros
- defines ArcEngine function binding macros
===========================================================================
*/

#ifdef ARC_PLATFORM_WINDOWS
#if ARC_DYNAMIC_LINK
	#ifdef ARC_BUILD_DLL // if building DLL, export; else, import
		#define ARCENGINE_API __declspec(dllexport)
	#else
		#define ARCENGINE_API __declspec(dllimport)
	#endif
#else
	#define ARCENGINE_API // as nothing
#endif
#else
	#error ArcEngine only supports Windows (for now)!
#endif

#ifdef ARC_ENABLE_ASSERTS
	#define ARC_ASSERT(x, ...) {if(!(x)) {ARC_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ARC_CORE_ASSERT(x, ...) {if(!(x)) {ARC_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ARC_ASSERT(x, ...)
	#define ARC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ARC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)