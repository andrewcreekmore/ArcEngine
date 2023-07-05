#include "ArcEnginePCH.h"
#include "WindowsInput.h"

#include "ArcEngine/Application.h"
#include <GLFW/glfw3.h>

/*
===========================================================================
WindowsInput: Win-platform-specific Input class implementation
- queries GLFW to determine input device states / positions
===========================================================================
*/

namespace ArcEngine
{
	Input* Input::s_Instance = new WindowsInput();

	//---------------------------// 

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	//---------------------------// 

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	//---------------------------// 

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos, (float)yPos };
	}

	//---------------------------// 

	float WindowsInput::GetMouseXImpl()
	{
		auto [xPos, yPos] = GetMousePositionImpl();
		return xPos;
	}

	//---------------------------// 

	float WindowsInput::GetMouseYImpl()
	{
		auto [xPos, yPos] = GetMousePositionImpl();
		return yPos;
	}
}