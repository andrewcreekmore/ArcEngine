#pragma once

#include "Core.h"

/*
===========================================================================
Input.h: global, platform-independent base class
- singleton
- contains protected pure virtual funcs to be implemented per platform
- implementations will determine input device states and positions
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API Input
	{
	public:

		// keyboard
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		// mouse
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:

		// per-platform implementations

		// keyboard
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		// mouse
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:

		static Input* s_Instance;
	};
}