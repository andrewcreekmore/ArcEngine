#include "ArcEnginePCH.h"
#include "WindowsWindow.h"

#include "ArcEngine/Events/ApplicationEvent.h"
#include "ArcEngine/Events/KeyEvent.h"
#include "ArcEngine/Events/MouseEvent.h"

//#include <glad/glad.h>

/*
===========================================================================
WindowsWindow: Win-platform specific implementation of Window class
- an interface representing a Windows-system based Window
===========================================================================
*/

namespace ArcEngine
{
	// for tracking if init completed / ready to terminate
	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		ARC_CORE_ERROR("GLFW Error ({0}: {1})", error, description);
	}

	//---------------------------// 

	Window* Window::Create(const WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Init(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	//---------------------------// 

	void WindowsWindow::Init(const WindowProperties& properties)
	{
		// create, setup, and track window
		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		ARC_CORE_INFO("Creating window: {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

		if (s_GLFWWindowCount == 0) // if GLFW not yet initialized, do so
		{
			int success = glfwInit();
			ARC_CORE_ASSERT(success, "Could not initiate GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		//int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//ARC_CORE_ASSERT(status, "Failed to initialize Glad!");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		++s_GLFWWindowCount;

		//---------------------------// 
		// set GLFW callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				// create ArcEngine event
				WindowResizeEvent event(width, height);
				data.Width = width;
				data.Height = height;

				// dispatch it
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				// create ArcEngine event + dispatch it
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						// create pressed event w/ a repeat count of 1 + dispatch it
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double YOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)YOffset);
				data.EventCallback(event);
			}); 

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	//---------------------------// 

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
			glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}