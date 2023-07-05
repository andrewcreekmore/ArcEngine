#pragma once

#include "ArcEngine/Window.h"

#include <GLFW/glfw3.h>

/*
===========================================================================
WindowsWindow: Win-platform specific Window class
- an interface representing a Windows-system based Window
===========================================================================
*/

namespace ArcEngine
{
	class WindowsWindow : public Window
	{
	public:

		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		// poll input events, swap buffers (GLFW)
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:

		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowData // for passing into GLFW
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}