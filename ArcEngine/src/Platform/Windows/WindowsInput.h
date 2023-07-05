#pragma once

#include "ArcEngine/Input.h"

/*
===========================================================================
WindowsInput: Win-platform-specific Input class implementation
- queries GLFW to determine input device states / positions
===========================================================================
*/

namespace ArcEngine
{
	class WindowsInput : public Input
	{
	protected:

		// overrides of pure virtual Input functions

		// keyboard
		virtual bool IsKeyPressedImpl(int keycode) override;

		// mouse
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}