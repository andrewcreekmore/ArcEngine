#pragma once

#include "ArcEnginePCH.h"

#include "ArcEngine/Core.h"
#include "ArcEngine/Events/Event.h"

/*
===========================================================================
Window.h: general Window base class
- a platform-independent *interface* representing a desktop-system based Window
===========================================================================
*/

namespace ArcEngine
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "ArcEngine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class ARCENGINE_API Window
	{
	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		// implemented per-platform
		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}