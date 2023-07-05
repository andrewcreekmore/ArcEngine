#pragma once

#include "Event.h"

/*
===========================================================================
KeyEvent.h: key-level input Events
- key press/release Events
===========================================================================
*/

namespace ArcEngine
{
	// common base class for all other KeyEvent types
	class ARCENGINE_API KeyEvent : public Event
	{
	public:

		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:

		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	//---------------------------// 

	class ARCENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:

		int m_RepeatCount;
	};

	//---------------------------// 

	class ARCENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}